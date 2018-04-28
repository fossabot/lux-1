#ifndef LSRTOKEN_H
#define LSRTOKEN_H

#include "sendtokenpage.h"
#include "receivetokenpage.h"
#include "addtokenpage.h"

#include <QWidget>
#include <QModelIndex>

class TokenViewDelegate;
class WalletModel;
class ClientModel;
class TokenItemModel;
namespace Ui {
class LSRToken;
}

class LSRToken : public QWidget
{
    Q_OBJECT

public:
    explicit LSRToken(QWidget *parent = 0);
    ~LSRToken();

    void setModel(WalletModel *_model);
    void setClientModel(ClientModel *clientModel);

Q_SIGNALS:

public Q_SLOTS:
    void on_goToSendTokenPage();
    void on_goToReceiveTokenPage();
    void on_goToAddTokenPage();
    void on_currentTokenChanged(QModelIndex index);
    void on_dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());

private:
    Ui::LSRToken *ui;
    SendTokenPage* m_sendTokenPage;
    ReceiveTokenPage* m_receiveTokenPage;
    AddTokenPage* m_addTokenPage;
    WalletModel* m_model;
    ClientModel* m_clientModel;
    TokenItemModel* m_tokenModel;
    TokenViewDelegate* m_tokenDelegate;
    QAction *m_sendAction;
    QAction *m_receiveAction;
    QAction *m_addTokenAction;
    QString m_selectedTokenHash;
};

#endif // LSRTOKEN_H
