import QtQuick 2.0
import ContactsModule.Base 1.0

BaseListView {
    id: root
    model: ListModel {
        ListElement {
            name: "Test11"
            surname: "Test12"
            phone: "Test13"
        }
        ListElement {
            name: "Test21"
            surname: "Test22"
            phone: "Test23"
        }
        ListElement {
            name: "Test31"
            surname: "Test32"
            phone: "Test33"
        }
        ListElement {
            name: "Test41"
            surname: "Test42"
            phone: "Test43"
        }
    }

    delegate: ContactDelegate {
        width: root.width
        height: 70
    }

}
