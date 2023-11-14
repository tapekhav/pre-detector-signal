#include <qt_plotter_controller.h>

#include <QLoggingCategory>

SignalController::SignalController(QLineEdit* lineEdit,
                                   QPushButton* button,
                                   SignalGenerator generator,
                                   QObject *parent)
                                   : QObject(parent),
                                     _begin_line_edit(lineEdit),
                                     _apply_button(button),
                                     _signal_generator(generator)
{
    connect(_apply_button, &QPushButton::clicked, this, &SignalController::onApplyButtonClicked);
}

void SignalController::onApplyButtonClicked()
{
    bool ok;
    double value = _begin_line_edit->text().toDouble(&ok);
    if (ok)
    {
        //_signal_generator->generateSignal(value);
    }
    else
    {
        //qWarning() << "Warning message.";
    }
}
