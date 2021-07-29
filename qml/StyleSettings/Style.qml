import QtQuick 2.0
pragma Singleton

QtObject {
    property bool isDarkStyle: true
    readonly property color primaryColor: isDarkStyle ? "#BB86FC" : "#6200EE"
    readonly property color backgroundColor: isDarkStyle ? "#121212" : "#FFFFFF"



    readonly property color textColor: isDarkStyle ? "#FFFFFF"
                                                   : "000000"

    readonly property color themeInvertedColor: isDarkStyle ? "#FFFFFF"
                                                            : "000000"


    readonly property real smallSpacing: 2

    readonly property real defaultOpacity : 1
    readonly property real emphasisOpacity : 0.87
    readonly property real secondaryOpacity : 0.6

    readonly property real defaulOffset: 5
    readonly property real mediumOffset: 10


}
