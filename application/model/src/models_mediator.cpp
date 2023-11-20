#include <models_mediator.h>

#include <file_reader.h>
#include <model_generator.h>
#include <binary_file_manager.h>

ModelsMediator::ModelsMediator(std::shared_ptr<FileReader> &file_reader,
                               std::shared_ptr<BinaryFileManager> &file_manager,
                               std::shared_ptr<ModelGenerator> &model_generator,
                               const std::string &config_file_name)
                               : _file_reader(file_reader),
                                 _file_manager(file_manager),
                                 _model_generator(model_generator),
                                 _parser(config_file_name)
{
    configureParser();

    std::shared_ptr<ModelsMediator> mediator_ptr(this);
    _file_manager->set_mediator(mediator_ptr);
    _file_reader->set_mediator(mediator_ptr);
    _model_generator->set_mediator(mediator_ptr);
}

void ModelsMediator::notify(EventType event) const
{
    _mediator_map.at(event)();
}

void ModelsMediator::configureParser()
{
    _parser.setData();
    _initial_model = std::move(_parser.getModel());
}

void ModelsMediator::writeToFile()
{
    auto models = _model_generator->getModels();

    _file_manager->setStartFrameMarker()
    for (size_t i = 0; i < models.size(); ++i)
    {
        _file_manager.
    }
}
