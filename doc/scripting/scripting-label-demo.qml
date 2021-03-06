import QtQml 2.0

/**
 * This script creates scripting labels
 * 
 */
QtObject {
    /**
     * Initializes the labels
     */
    function init() {
        script.registerLabel("html-label", "<strong>Strong</strong> HTML text<br />with three lines<br />and a <a href='http://www.qownnotes.org'>link to a website</a>.");

        script.registerLabel("long-label", "an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text, an other very long text that will wrap");

        script.registerLabel("counter-label");
    }

    /**
     * This starts a timer that triggers two seconds
     */
    property QtObject timer: Timer {
        interval: 1000
        repeat: true
        running: true

        property int count: 0

        onTriggered: {
            count++;
            script.setLabelText("counter-label", "count = " + count);
        }
    }
}
