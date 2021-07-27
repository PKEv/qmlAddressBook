import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        width: root.height
        height: root.height
        source: Resorces.contacts.defaultContactIcon
    }
    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right
        anchors.leftMargin: Style.defaulOffset
        Row {
            spacing: Style.smallSpacing

            BaseText {
                text: name
            }
            BaseText {
                text: surname
            }
        }
        BaseText {
            text: "+" + phone
            color: Style.primaryColor
        }
    }
}
