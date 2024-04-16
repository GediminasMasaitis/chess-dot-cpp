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

constexpr int32_t quantization1 = 16;
constexpr int32_t quantization2 = 256;

template<class T>
static T Read(std::istream& stream, int32_t quantization)
{
    constexpr size_t size = sizeof(float);
    char buffer[size];
    stream.read(buffer, size);
    const float* resultPtr = reinterpret_cast<float*>(buffer);
    const auto result = *resultPtr;
    const auto quantized_result = static_cast<T>(std::round(result * quantization));
    return quantized_result;
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
            const NnueValue weight = Read<int16_t>(file, quantization1);
            InputWeights[inputIndex][hiddenIndex] = weight;
        }
    }

    for (size_t hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
    {
        assert(!file.eof());
        const NnueValue bias = Read<int16_t>(file, quantization1);
        HiddenBiases[hiddenIndex] = bias;
    }

    for (auto hiddenNum = 0; hiddenNum < 2; hiddenNum++)
    {
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue weight = Read<int16_t>(file, quantization2);
            HiddenWeightses[hiddenNum][hiddenIndex] = weight;
        }
    }

    assert(!file.eof());
    OutputBias = Read<int32_t>(file, quantization1 * quantization2);

    assert(static_cast<size_t>(file.tellg()) == sizeof(float) * (InputCount * HiddenCount + HiddenCount + HiddenCount * 2 + 1));
#endif
}
