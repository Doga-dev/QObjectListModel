import QtQuick 2.15
import QtQuick.Controls 2.15
import App 1.0
import "."

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("User Management")

    Users {
        id: usersController

        Component.onCompleted: {
            addUser("Francis", "Chapet", Date("18", "6", "1944"), "fc", "FR");
            addUser("Hugo", "Maxime", Date("1", "1", "2000"), "hm", "UK");
            addUser("Alice", "Doe", Date("10", "12", "1981"), "ad", "US");
        }
    }

    Column {
        anchors.fill: parent

        // Header Row for Sorting
        Row {
            width: parent.width
            height: 40
            spacing: 20

            Rectangle {
                width: 100
                height: parent.height
                color: "lightgray"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("First Name")
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (usersController.usersModel.sortField === "firstName") {
                            usersController.usersModel.sortOrder = usersController.usersModel.sortOrder === Qt.AscendingOrder ? Qt.DescendingOrder : Qt.AscendingOrder
                        } else {
                            usersController.setSortField("firstName", Qt.AscendingOrder)
                        }
                    }
                }
            }

            Rectangle {
                width: 100
                height: parent.height
                color: "lightgray"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("Last Name")
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (usersController.usersModel.sortField === "lastName") {
                            usersController.usersModel.sortOrder = usersController.usersModel.sortOrder === Qt.AscendingOrder ? Qt.DescendingOrder : Qt.AscendingOrder
                        } else {
                            usersController.setSortField("lastName", Qt.AscendingOrder)
                        }
                    }
                }
            }

            Rectangle {
                width: 100
                height: parent.height
                color: "lightgray"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("Age")
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (usersController.usersModel.sortField === "age") {
                            usersController.usersModel.sortOrder = usersController.usersModel.sortOrder === Qt.AscendingOrder ? Qt.DescendingOrder : Qt.AscendingOrder
                        } else {
                            usersController.usersModel.setSortField("age", Qt.AscendingOrder)
                        }
                    }
                }
            }
        }

        // User List View
        ListView {
            id: userListView
            width: parent.width
            height: parent.height - 100
            model: usersController.usersModel
            delegate: Item {
                width: parent.width
                height: 40
                Row {
                    spacing: 20
                    Text { width: 100; text: model.firstName }
                    Text { width: 100; text: model.lastName }
                    Text { width: 100; text: model.age }
                    Button {
                        text: qsTr("Edit")
                        onClicked: {
                            editUserDialog.index = index
                            editUserDialog.user = modelData
                            editUserDialog.open()
                        }
                    }
                    Button {
                        text: qsTr("Delete")
                        onClicked: {
                            deleteUserDialog.text = qsTr("Are you sure you want to delete this user?")
                            deleteUserDialog.visible = true
                        }
                    }
                }
            }
        }
    }

    Button {
        text: qsTr("Add User")
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: addUserDialog.open()
    }

    Dialog {
        id: addUserDialog
        title: qsTr("Add User")
        standardButtons: Dialog.Ok | Dialog.Cancel
        contentItem: Column {
            spacing: 10
            TextField { id: firstNameInput; placeholderText: qsTr("First Name") }
            TextField { id: lastNameInput; placeholderText: qsTr("Last Name") }
            DatePicker { id: birthDayInput; title: qsTr("Birth Date") }
            TextField { id: loginInput; placeholderText: qsTr("Login") }
            TextField { id: countryInput; placeholderText: qsTr("Country") }
        }
        onAccepted: {
            if (usersController.addUser(firstNameInput.text, lastNameInput.text, birthDayInput.selectedDate, loginInput.text, countryInput.text)) {
                addUserDialog.close()
            } else {
                messageDialog.text = qsTr("Login already exists!")
                messageDialog.open()
            }
        }
    }

    Dialog {
        id: editUserDialog
        title: qsTr("Edit User")
        standardButtons: Dialog.Ok | Dialog.Cancel
        property int index: -1
        property Person user: null
        contentItem: Column {
            spacing: 10
            TextField { id: editFirstNameInput; placeholderText: qsTr("First Name"); text: (editUserDialog.user ? editUserDialog.user.firstName : ""); }
            TextField { id: editLastNameInput; placeholderText: qsTr("Last Name"); text: (editUserDialog.user ? editUserDialog.user.lastName : ""); }
            DatePicker { id: editBirthDayInput; title: qsTr("Birth Date"); selectedDate: (editUserDialog.user ? editUserDialog.user.birthday : new Date()); }
            TextField { id: editLoginInput; placeholderText: qsTr("Login"); text: (editUserDialog.user ? editUserDialog.user.login : ""); }
            TextField { id: editCountryInput; placeholderText: qsTr("Country"); text: (editUserDialog.user ? editUserDialog.user.country : ""); }
        }
        onAccepted: {
            if (usersController.editUser(index, editFirstNameInput.text, editLastNameInput.text, editBirthDayInput.selectedDate, editLoginInput.text, editCountryInput.text)) {
                editUserDialog.close()
                user = null;
            } else {
                messageDialog.text = qsTr("Login already exists!")
                messageDialog.open()
            }
        }
    }

    MessageDialog {
        id: messageDialog
    }
}
