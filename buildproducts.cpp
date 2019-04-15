#include "buildproducts.h"

buildProducts::buildProducts(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant buildProducts::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex buildProducts::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex buildProducts::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int buildProducts::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int buildProducts::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant buildProducts::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
