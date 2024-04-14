#include "evaluationNnueBase.h"

#include <sstream>

#if ENABLE_INCBIN
#include "external/incbin/incbin.h"
INCBIN(network, EVALFILE);
#endif

using namespace std;

void EvaluationNnueBase::SetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece, const EachColor<bool>& kingsQueenSide, const EachColor<bucket_t>& buckets)
{
    ApplyPiece<true>(hiddenLayers, pos, piece, kingsQueenSide, buckets);
}

void EvaluationNnueBase::UnsetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece, const EachColor<bool>& kingsQueenSide, const EachColor<bucket_t>& buckets)
{
    ApplyPiece<false>(hiddenLayers, pos, piece, kingsQueenSide, buckets);
}

void EvaluationNnueBase::ResetSingle(hidden_layer_t& hiddenLayer)
{
    std::copy(std::begin(HiddenBiases), std::end(HiddenBiases), std::begin(hiddenLayer));
}

void EvaluationNnueBase::Reset(hidden_layers_t& hiddenLayers)
{
    for (Color color = 0; color < Colors::Count; color++)
    {
        auto& hiddenLayer = hiddenLayers[color];
        ResetSingle(hiddenLayer);
    }
}

template<class T>
static T Read(std::istream& stream)
{
    constexpr size_t size = sizeof(T);
    char buffer[size];
    stream.read(buffer, size);
    const T* resultPtr = reinterpret_cast<T*>(buffer);
    const auto result = *resultPtr;
    return result;
}

void EvaluationNnueBase::Init()
{
#if NNUE
#if ENABLE_INCBIN
    auto file = stringstream(ios::in | ios::out | ios::binary);
    file.write(reinterpret_cast<const char*>(gnetworkData), gnetworkSize);
#else
    const auto& path = Options::NnuePath;
    auto file = ifstream(path, ios::binary);
    if (!file.good())
    {
        std::cout << "Error opening NNUE file \"" << path << "\"" << std::endl;
        return;
    }
#endif

    for (size_t inputIndex = 0; inputIndex < InputCount; inputIndex++)
    {
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue weight = Read<int16_t>(file);
            InputWeights[inputIndex][hiddenIndex] = weight;
        }
    }

    for (size_t hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
    {
        assert(!file.eof());
        const NnueValue bias = Read<int16_t>(file);
        HiddenBiases[hiddenIndex] = bias;
    }

    for (auto hiddenNum = 0; hiddenNum < 2; hiddenNum++)
    {
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue weight = Read<int16_t>(file);
            HiddenWeightses[hiddenNum][hiddenIndex] = weight;
        }
    }

    assert(!file.eof());
    OutputBias = Read<int16_t>(file);

    assert(static_cast<size_t>(file.tellg()) == sizeof(NnueValue) * (InputCount * HiddenCount + HiddenCount + HiddenCount * 2) + sizeof(OutputBias));
#endif
}
