#ifndef SETPINPAGE_H
#define SETPINPAGE_H

#include <QWidget>

namespace Ui {
class SetPinPage;
}

enum class PinPageState : std::int8_t
{
    Init,
    ReEnter,
    ReadyToVerify
};

class SetPinPage : public QWidget
{
    Q_OBJECT

public:
    explicit SetPinPage(QWidget *parent = 0);
    ~SetPinPage();

Q_SIGNALS:
    void digitClicked(char digit);
    void backspaceClicked();
    void backToPreviousPage();
    void pinEntered();
    void pinReEntered();
    void pinReadyForVerification(QString pin);
    void pinValidationFailed();

protected:
    void paintEvent(QPaintEvent *event) override;
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    void initSetPinLayout();
    void initReEnterPinLayout();

private Q_SLOTS:
    void onDigitClicked(char digit);
    void onBackspaceClicked();
    void onPinEntered();
    void onPinReEntered();
    void onBackClicked();

private:
    Ui::SetPinPage *ui;
    PinPageState pageState;
    QString pin;
    QString pinToVerify;
    bool initialPinEntered;
};

#endif // SETPINPAGE_H