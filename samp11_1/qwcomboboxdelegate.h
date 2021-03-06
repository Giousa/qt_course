#ifndef QWCOMBOBOXDELEGATE_H
#define QWCOMBOBOXDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>

class QWComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWComboBoxDelegate(QObject *parent = nullptr);

    void setItems(QStringList items,bool isEdit);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    QStringList m_ItemList;
    bool m_isEdit;

signals:

};

#endif // QWCOMBOBOXDELEGATE_H
