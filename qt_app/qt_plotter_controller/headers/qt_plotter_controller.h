#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_CONTROLLER_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_CONTROLLER_H

#include <memory>

#include <QObject>
#include <QLineEdit>
#include <QPushButton>

#include <generate_signal.h>

#include <bpsk_modulation_factory.h>

class SignalController : public QObject
{
    Q_OBJECT
public:
    SignalController(QLineEdit* lineEdit,
                     QPushButton* button,
                     SignalGenerator generator,
                     QObject *parent = nullptr);

public slots:
    void onApplyButtonClicked();
private:
    std::unique_ptr<QLineEdit> _begin_line_edit;
    std::unique_ptr<QPushButton> _apply_button;
    SignalGenerator _signal_generator;
};

#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_CONTROLLER_H
