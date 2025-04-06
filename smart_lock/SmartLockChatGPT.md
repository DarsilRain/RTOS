⚙️ Smart Door Lock System
💡 Project Overview:

Simulate a smart door lock using buttons, LEDs, and a keypad (or serial input if no keypad). The system has different states (locked, unlocked, error, admin mode), and tasks respond to events like button presses, timeouts, and password entry.
🧠 Concepts You’ll Learn:
Concept	What You'll Implement
Event-driven programming	Tasks wake on external input (buttons/serial), inter-task messages
State machines	Manage door states (LOCKED, UNLOCKED, ADMIN, ERROR)
Semaphores	Coordinate shared resources like the door lock motor or state transitions
Queues or Event Groups	Pass messages or signals between tasks
Software timers	For lock timeouts or delayed relocking
🔩 Suggested Hardware:

    Arduino Mega

    4x4 Keypad (or Serial input)

    Servo or LED for door lock simulation

    Pushbutton (simulate door open/close sensor)

    Optional: OLED/LCD for state display

🔄 System States (Example FSM):

    Locked

        Await password

    Unlocked

        Auto-relocks after timeout

    Error

        After 3 wrong attempts → lockout mode

    Admin

        Accessed via special code; can reset password or view log

🧵 Suggested Task Breakdown:
Task	Function
InputTask	Reads keypad or serial input, sends input to queue
FSMTask	Receives events and controls the state machine
LockControlTask	Opens/closes lock based on state transitions
TimerTask	Handles relock timeouts and error recovery
DisplayTask	Optional: shows current state on OLED/LCD
💬 Events to Trigger FSM:

    PASSWORD_ENTERED_CORRECT

    PASSWORD_INCORRECT

    TIMEOUT

    ADMIN_CODE_ENTERED

    LOCK_COMMAND, UNLOCK_COMMAND

🛠️ Bonus Ideas to Expand:

    Add EEPROM storage for passwords

    Use event groups to manage multiple simultaneous conditions (e.g., door open + admin mode)

    Add logging (e.g., "3 failed attempts at 5:30 PM")

    Use a watchdog to restart the system if it hangs