import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Column {
        anchors.fill: parent

        ComboBox {
            id: classComboBox
            model: provider.my_classes
            onCurrentIndexChanged: {
                var selectedClass = classComboBox.currentText;
                var members = provider.getClassMembers(selectedClass);
                memberComboBox.model = members
            }
        }

        ComboBox {
            id: memberComboBox
        }

        // TreeView {
        //     TableViewColumn {
        //         title: "Name"
        //         role: "fileName"
        //         width: 300
        //     }
        //     TableViewColumn {
        //         title: "Permissions"
        //         role: "filePermissions"
        //         width: 100
        //     }
        //     //model: provider.my_classes
        // }
    }

}
