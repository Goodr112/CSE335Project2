#include "visitproducts.h"

visitProducts::visitProducts(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant visitProducts::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex visitProducts::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex visitProducts::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int visitProducts::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int visitProducts::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant visitProducts::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
