#include <models_mediator.h>

#include <file_reader.h>
#include <model_generator.h>
#include <binary_file_manager.h>

#include <full_encode_number.h>

static const std::map<size_t, std::function<double(const Model& model)>> kModelMap =
{
    {0, [](const Model& model) { return model.temperature(); }},
    {1, [](const Model& model) { return model.wind_speed().x(); }},
    {2, [](const Model& model) { return model.wind_speed().y(); }},
    {3, [](const Model& model) { return model.wgs().coordinates().x(); }},
    {4, [](const Model& model) { return model.wgs().coordinates().y(); }},
    {5, [](const Model& model) { return model.wgs().coordinates().z(); }},
    {6, [](const Model& model) { return model.wgs().speed().z(); }},
    {7, [](const Model& model) { return model.humidity(); }},
    {8, [](const Model& model) { return model.board_voltage(); }},
    {9, [](const Model& model) { return model.control_voltage(); }}
};

ModelsMediator::ModelsMediator(std::shared_ptr<FileReader> &file_reader,
                               std::shared_ptr<BinaryFileManager> &file_manager,
                               std::shared_ptr<ModelGenerator> &model_generator)
                               : _file_reader(file_reader),
                                 _file_manager(file_manager),
                                 _model_generator(model_generator)
{
    std::shared_ptr<ModelsMediator> mediator_ptr(this);
    _file_manager->set_mediator(mediator_ptr);
    _file_reader->set_mediator(mediator_ptr);
    _model_generator->set_mediator(mediator_ptr);
}

void ModelsMediator::notify(EventType event) const
{
    _mediator_map.at(event)();
}

void ModelsMediator::writeToFile()
{
    auto models = _model_generator->getModels();
    auto time_step = _model_generator->getTimeInterval().step;

    for (size_t i = 0; i < models.size(); ++i)
    {
        _file_manager->setStartFrameMarker(i, EncodeData(static_cast<double>(i) * time_step).execute());
        writeModel(models[i]);
    }
    notify(EventType::WriteToFile);
}

void ModelsMediator::writeModel(const Model& model)
{
    for (size_t i = 0; i < 10; ++i)
    {
        writeWord(i, model);
    }
}

void ModelsMediator::writeWord(size_t i, const Model& model)
{
    _file_manager->addSynchronize();

    auto param = kModelMap.at(i)(model);
    _file_manager->writeBitset(EncodeData(param).execute());
}

void ModelsMediator::readFromFile()
{
    _file_reader->readAllFile();
}

void ModelsMediator::doPreDetectorSignal()
{
    auto info = _file_reader->getFileInfo();

    std::vector<bool> bool_info;
    std::transform(info.begin(), info.end(), std::back_inserter(bool_info), [](char c) { return c == '1'; });


}
