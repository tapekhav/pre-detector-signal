#ifndef PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H

#include <string>

#include <model.pb.h>
#include <interface_mediator.h>
#include <config_parser.h>

class ModelGenerator;
class FileReader;
class BinaryFileManager;

class ModelsMediator final : public IMediator
{
public:
    ModelsMediator(std::shared_ptr<FileReader> &file_reader,
                   std::shared_ptr<BinaryFileManager> &file_manager,
                   std::shared_ptr<ModelGenerator> &model_generator,
                   const std::string &config_file_name=path_to_config);

    void notify(EventType event) const final;

    ~ModelsMediator() final = default;
private:
    void configureParser();

    void writeToFile();
private:
    std::shared_ptr<FileReader> _file_reader;
    std::shared_ptr<ModelGenerator> _model_generator;
    std::shared_ptr<BinaryFileManager> _file_manager;

    ConfigParser _parser;
    Model _initial_model;

    const std::map<EventType, std::function<void()>> _mediator_map =
    {
            {EventType::GenerateModel, },
            {EventType::WriteToFile, },
            {EventType::ReadFromFile, }
    };
};

#endif //PRE_DETECTOR_SIGNAL_MODELS_MEDIATOR_H
