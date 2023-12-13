#ifndef PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H

#include <string>

#include <model.pb.h>
#include <interface_mediator.h>
#include <signal-to-noise_ratio.h>
#include <complex_signal_spectrum.h>
#include <bpsk_modulation_factory.h>
#include <analog-to-digital_conversion.h>
#include <vector>

class ModelGenerator;
class FileReader;
class BinaryFileManager;

class FileMediator final : public IMediator
{
public:
    FileMediator(std::shared_ptr<FileReader> &file_reader,
                   std::shared_ptr<BinaryFileManager> &file_manager,
                   std::shared_ptr<ModelGenerator> &model_generator);

    void notify(EventType event) const final;

    [[nodiscard]] inline std::vector<bool> getInfoBits() const { return _info_bits; }

    ~FileMediator() final = default;
private:
    void writeToFile();

    void writeModel(const Model& model);

    void writeWord(size_t i, const Model& model);

    void readFromFile();

    void doPreDetectorSignal();
private:
    std::shared_ptr<FileReader> _file_reader;
    std::shared_ptr<ModelGenerator> _model_generator;
    std::shared_ptr<BinaryFileManager> _file_manager;

    std::vector<bool> _info_bits;

    const std::map<EventType, std::function<void()>> _mediator_map =
    {
            {EventType::GenerateModel, [this]() { writeToFile(); }},
            {EventType::WriteToFile, [this]() { readFromFile(); }},
            {EventType::ReadFromFile, [this]() { doPreDetectorSignal(); }}
    };

    std::vector<std::pair<size_t, double>> _info_about_frames;
};

#endif //PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H
