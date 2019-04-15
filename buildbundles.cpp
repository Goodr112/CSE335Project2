#include "buildbundles.h"

buildBundles::buildBundles(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant buildBundles::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex buildBundles::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex buildBundles::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int buildBundles::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int buildBundles::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant buildBundles::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
