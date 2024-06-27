import QtQuick 2.15
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as C1

/*ApplicationWindow*/ Item {
    visible: true

    C1.TreeView {
        id: treeView
        anchors.fill: parent
        model: mymodel
        itemDelegate: Rectangle {
            color: ( styleData.row % 2 == 0 ) ? "white" : "lightblue"
            height: 20

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: styleData.value === undefined ? "" : styleData.value // The branches don't have a description_role so styleData.value will be undefined
            }
        }

        Component.onCompleted: {
            createColumns();
        }

        function createColumns() {
            // clear all columns
            var i;
            for (i = treeView.columnCount - 1; i >= 0; --i) {
                treeView.removeColumn(i);
            }

            // create all selected columns
            for (i = 0; i < mymodel.getColumns(); ++i) {
                var columnComponent = Qt.createComponent("TableViewColumn.qml");
                if (columnComponent.status === Component.Ready) {
                    var columnObject = columnComponent.createObject(treeView);
                    columnObject.role = mymodel.getRole(i);
                    columnObject.title = mymodel.getTableName(i);
                    columnObject.width = 100;

                    // add column
                    treeView.addColumn(columnObject);
                } else {
                    console.error("Error creating column component:", columnComponent.errorString());
                }
            }
        }
    }
}
