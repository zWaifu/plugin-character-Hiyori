#ifndef HIYORI_H
#define HIYORI_H

#include <QObject>

#include "Hiyori_global.h"
#include "IzWaifuCharacterPlugin.h"

class HIYORI_EXPORT Hiyori : public QObject, public IzWaifuCharacterPlugin
{
    Q_OBJECT
    Q_INTERFACES(IzWaifuCharacterPlugin)
    Q_PLUGIN_METADATA(IID zWaifuCharacterPluginInterface_iid FILE "hiyori.json")
public:
    Hiyori();

    // IzWaifuCharacterPlugin interface
public:
    virtual void initialize(QSharedPointer<const AzWaifuEngine> engine) override;
    virtual QString modelName() const override;
    virtual QString modelFileName() const override;
    virtual QByteArray loadFile(const QString &relativePath) const override;
    virtual QUuid id() const override;

private:
    static const QString _modelName;
    static const QString _modelFileName;
    static const QUuid _modelId;
    QSharedPointer<const AzWaifuEngine> _engine;
};

#endif // HIYORI_H
