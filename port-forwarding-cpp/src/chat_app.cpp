//
// Created by root on 5/24/22.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using std::cout;
using std::cin;


enum AppState {
    COMMAND,
    CHAT
} app_state;


std::vector<std::string> parse_command(const std::string& line) {

    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;

    while(iss >> word) {
        words.push_back(word);
    }

    return words;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {

        std::cerr << "Usage: " << argv[0] << " server_port\n";
        return 1;
    }

    std::string server_port = argv[1];
    app_state = COMMAND;
    std::string msg;
    std::vector<std::string> cmdWords;

    // TODO: launch asynch. server listener
    cout << "# Server is listening at port: " << server_port << "\n";

    cout << "$ Entering command mode, available commands:\n";
    cout << "\tconnect ip port\n\texit\n";

    while (cin.good()) {

        if (app_state == COMMAND) {

            cout << "$ ";
            getline(cin, msg);

            cmdWords = parse_command(msg);

            if (cmdWords.empty()) {
                // do nothing
            }
            else if (cmdWords[0] == "exit") {
                // cleanup
                break;
            }
            else if (cmdWords[0] == "connect") {

                if (cmdWords.size() == 3) {
                    // TODO: connect to server
                    cout << "\tConnecting to server ...\n";
                }
                else {
                    cout << "\tUsage: " << cmdWords[0] << " ip port\n";
                }
            }
            else {
                cout << "\tUnknown command: " << msg << std::endl;
            }
        }
        else if (app_state == CHAT) {

            cout << "> ";
            getline(cin, msg);

            if (msg == "exit") {
                app_state = COMMAND;
            }
            else {
                // TODO: send the message
            }
        }
        else {
            cout << "** Error: Undefined app state: " << app_state << std::endl;
            return 2;
        }
    }

    cout << "\nClosing session!\n";
    return 0;
}



