import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaulOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 15
        height: root.height - 15
        image.source: Resorces.contacts.defaultContactIcon
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
