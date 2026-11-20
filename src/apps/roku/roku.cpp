#include "apps/apps.h"

// Setup
int screen_w = 0;
int screen_h = 0;
int margin = 0;
int spacer = 0;

// Main Layout (3 Columns)
int x = 0;
int y = 0;
int w = 0;
int h = 0;

// Quick Buttons (6 Columns)
int quick_w = 0;
int quick_h = 0;

// Bottom Navigation
int bottom_y = 0;

// Home Button
Button* HomeButton = nullptr;
// Remote buttons
Button* upButton = nullptr;
Button* downButton = nullptr;
Button* leftButton = nullptr;
Button* rightButton = nullptr;
Button* okButton = nullptr;
// Volume buttons
Button* volumeUpButton = nullptr;
Button* volumeDownButton = nullptr;
// Bottom section buttons
Button* oneButton = nullptr;
Button* twoButton = nullptr;
Button* threeButton = nullptr;
// Quick buttons
Button* HBOButton = nullptr;
Button* NetflixButton = nullptr;
Button* CrunchyrollButton = nullptr;
Button* DisneyPlusButton = nullptr;
Button* ChosenButton = nullptr;
Button* YoutubeButton = nullptr;
// Values
// Values
const char* home = "home";
const char* up = "up";
const char* down = "down";
const char* left = "left";
const char* right = "right";
const char* select = "select";
const char* volume_up = "volume_up";
const char* volume_down = "volume_down";
const char* hbo = "hbo";
const char* netflix = "netflix";
const char* crunchyroll = "crunchyroll";
const char* disney_plus = "disney_plus";
const char* chosen = "chosen";
const char* youtube = "youtube";

// layout
int layout = 0;

void roku_commands(const char* command){
    log("Roku", "Initializing");

    // Getting Token
    String token = get_token();

    // Checking if Session Token Exists
    if (token.isEmpty()) {
        log("Storage", "No Session_Token found!");
        return;
    }

    // Createing Json Document Object
    JsonDocument request;
    request["session_token"] = token;
    request["command"] = command;
    
    // Createing String
    String body;

    // Turning json document into a string
    serializeJson(request, body);

    // Createing Json Response Object
    JsonDocument response;
    
    // Using Jax Http request
    if (!jax_request("roku/commands", body, response, true, token)) {
        return;
    }

}

void create_buttons() {
    // Remote Buttons
    upButton = new Button("Up", x+w+spacer, y, w, h, BLUE, epd_bitmap_icons8_home_50);
    leftButton = new Button("Left", x, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    okButton = new Button("OK", x+w+spacer, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    rightButton = new Button("Right", x+w*2+spacer*2, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    downButton = new Button("Down", x+w+spacer, y+h*2+spacer*2, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Home Button
    HomeButton = new Button("Home", x+w+spacer, y+h*3+spacer*3, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Volume Buttons
    volumeUpButton = new Button("Volume Up", x, y, w, h, BLUE, epd_bitmap_icons8_home_50);
    volumeDownButton = new Button("Volume Down", x+w*2+spacer*2, y, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Quick Buttons (3 Columns x 2 Rows)
    int quick_w = w;
    int quick_h = h;
    int quick_y = y+h+spacer;

    HBOButton = new Button("HBO", x, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    NetflixButton = new Button("Netflix", x+w+spacer, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    CrunchyrollButton = new Button("Crunchyroll", x+w*2+spacer*2, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    DisneyPlusButton = new Button("Disney+", x, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    ChosenButton = new Button("Chosen", x+w+spacer, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    YoutubeButton = new Button("YouTube", x+w*2+spacer*2, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);

    // Bottom Navigation Buttons
    oneButton = new Button("1", x, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
    twoButton = new Button("2", x+w+spacer, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
    threeButton = new Button("3", x+w*2+spacer*2, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
}
void roku_setup() {
    // Setup
    screen_w = gfx->width();
    screen_h = gfx->height();
    margin = 20;
    spacer = 10;
    
    // Main Layout (3 Columns)
    x = margin;
    y = margin;
    w = (screen_w - margin * 2 - spacer * 2) / 3;
    h = (screen_h - margin * 2 - spacer * 3) / 4;
    
    // Quick Buttons (6 Columns)
    quick_w = (screen_w - margin * 2 - spacer * 5) / 6;
    quick_h = h;
    
    // Bottom Navigation
    bottom_y = screen_h - margin - h;
    create_buttons();
}

/*----------Layout----------*/
void remote_layout(TouchPoint pressed) {
    upButton->draw("^", WHITE, 2);
    leftButton->draw("<", WHITE, 2);
    okButton->draw("OK", WHITE, 2);
    rightButton->draw(">", WHITE, 2);
    downButton->draw("v", WHITE, 2);
    HomeButton->draw("Home", WHITE, 2);

    // Hit
    upButton->push(pressed, roku_commands, up);
    downButton->push(pressed, roku_commands, down);
    leftButton->push(pressed, roku_commands, left);
    rightButton->push(pressed, roku_commands, right);
    okButton->push(pressed, roku_commands, select);
    HomeButton->push(pressed, roku_commands, home);

}

void volume_layout(TouchPoint pressed) {
    // Drawing Buttons
    volumeUpButton->draw("Volume Up", WHITE, 2);
    volumeDownButton->draw("Volume Down", WHITE, 2);

    // Button Being Pressed
    volumeUpButton->push(pressed, roku_commands, volume_up);
    volumeDownButton->push(pressed, roku_commands, volume_down);
}

void quick_buttons_layout(TouchPoint pressed) {
    // Drawing Buttons
    HBOButton->draw("HBO", WHITE, 2);
    NetflixButton->draw("Netflix", WHITE, 2);
    CrunchyrollButton->draw("Crunchyroll", WHITE, 2);
    DisneyPlusButton->draw("Disney+", WHITE, 2);
    ChosenButton->draw("Chosen", WHITE, 2);
    YoutubeButton->draw("YouTube", WHITE, 2);

    // Button Being Pressed
    HBOButton->push(pressed, roku_commands, hbo);
    NetflixButton->push(pressed, roku_commands, netflix);
    CrunchyrollButton->push(pressed, roku_commands, crunchyroll);
    DisneyPlusButton->push(pressed, roku_commands, disney_plus);
    ChosenButton->push(pressed, roku_commands, chosen);
    YoutubeButton->push(pressed, roku_commands, youtube);
}

void bottom_section(TouchPoint pressed) {
    // Drawing Buttons
    oneButton->draw("1", WHITE, 2);
    twoButton->draw("2", WHITE, 2);
    threeButton->draw("3", WHITE, 2);

    // Button Being Pressed
    oneButton->hit(pressed, layout_one);
    twoButton->hit(pressed, layout_two);
    threeButton->hit(pressed, layout_three);
}

void current_layout(TouchPoint pressed) {
    switch (layout) {
        case 0:
            clear();
            remote_layout(pressed);
            break;
        case 1:
            clear();
            volume_layout(pressed);
            break;
        case 2:
            clear();
            quick_buttons_layout(pressed);
            break;
        default:
            clear();
            remote_layout(pressed);
            break;
    }
    // Bottom Section Buttons
    bottom_section(pressed);

}

void layout_one(TouchPoint pressed) {
    layout = 0;
    current_layout(pressed);
}

void layout_two(TouchPoint pressed) {
    layout = 1;
    current_layout(pressed);
}

void layout_three(TouchPoint pressed) {
    layout = 2;
    current_layout(pressed);
}



void roku_run(TouchPoint pressed) {
    // Drawing Current Layout
    current_layout(pressed);

    

}