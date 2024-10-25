import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    id: datePicker
    width: 300
    height: childrenRect.height
    spacing: 0

    property alias title: idTitle.text
    property date selectedDate: new Date()

    // signal dateChanged(date selected)

    Text {
        id: idTitle
        text: qsTr("Title")
    }
    Row {
        width: childrenRect.width
        height: childrenRect.height
        spacing: 10

        ComboBox {
            id: dayComboBox
            model: ListModel {
                Component.onCompleted: {
                    for (var i = 1; i <= 31; i++) {
                        append({"day": i})
                    }
                }
            }
            textRole: "day"
            onCurrentIndexChanged: datePicker.updateDate()
        }

        ComboBox {
            id: monthComboBox
            model: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
            onCurrentIndexChanged: datePicker.updateDate()
        }

        ComboBox {
            id: yearComboBox
            model: ListModel {
                Component.onCompleted: {
                    for (var i = new Date().getFullYear(); i >= 1900; i--) {
                        append({"year": i})
                    }
                }
            }
            textRole: "year"
            onCurrentIndexChanged: datePicker.updateDate()
        }
    }

    property var date: new Date(yearComboBox.currentText, monthComboBox.currentIndex, dayComboBox.currentText)

    function updateDate() {
        selectedDate = new Date(yearComboBox.currentText, monthComboBox.currentIndex, dayComboBox.currentText)
        // dateChanged(selectedDate)
    }
}
