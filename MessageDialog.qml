import QtQuick 2.15
import QtQuick.Controls 2.15

Dialog {
    id: dialog
    title: "Message"
    standardButtons: Dialog.Ok | Dialog.Cancel

    property alias text: messageLabel.text

    contentItem: Column {
        spacing: 10
        Label {
            id: messageLabel
            wrapMode: Text.Wrap
            text: "Message text goes here."
        }
    }
}
