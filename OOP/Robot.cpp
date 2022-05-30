// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q35
#include <sstream>
using namespace std;

int main() {
    Robot robot;
    string in;
    getline(cin, in);
    while (in != "" && in != "STOP")
    {
        stringstream ss(in);
        string cmd;
        ss >> cmd;
        if(cmd == "GO") {
            int nStep;
            ss >> nStep;
            while (nStep > 0)
            {
                robot.go();
                nStep--;
            }
        }
        else if(cmd == "TURN") {
            string dir;
            ss >> dir;
            robot.turn(dir);
        }
        else if(cmd == "TURNTO") {
            char to;
            ss >> to;
            while(robot.getDirection() != to) {
                robot.turn("LEFT");
            }
        }
        else if(cmd == "GOTO") {
            int x, y, curX, curY;
            ss >> x >> y;
            curX = robot.getPositionX();
            curY = robot.getPositionY();
            int deltaX = x - curX;
            int deltaY = y - curY;
            if(deltaX > 0) {
                while(robot.getDirection() != 'E')
                    robot.turn("LEFT");
                while(deltaX > 0) {
                    robot.go();
                    deltaX--;
                }
            }
            if(deltaX < 0) {
                while(robot.getDirection() != 'W')
                    robot.turn("LEFT");
                while(deltaX < 0) {
                    robot.go();
                    deltaX++;
                }
            }
            if(deltaY > 0) {
                while(robot.getDirection() != 'N')
                    robot.turn("LEFT");
                while(deltaY > 0) {
                    robot.go();
                    deltaY--;
                }
            }
            if(deltaY < 0) {
                while(robot.getDirection() != 'S')
                    robot.turn("LEFT");
                while(deltaY < 0) {
                    robot.go();
                    deltaY++;
                }
            }
            while(robot.getDirection() != 'N')
                robot.turn("LEFT");
        }
        else if(cmd == "SHOWINFO") {
            robot.display();
        }
        getline(cin, in);
    }
    
    return 0;
}
