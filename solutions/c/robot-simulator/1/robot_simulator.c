#include "robot_simulator.h"

#include <stdlib.h>
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    return (robot_status_t){
        .direction = direction,
        .position = (robot_position_t){
            .x = x,
            .y = y,
        }
    };
}

typedef enum {
    RIGHT,
    LEFT,
    ADVANCE,
} movement_t;

static void make_move(robot_status_t* robot, movement_t m)
{
    robot_direction_t direction = robot->direction;

    switch (m) {
        case RIGHT:
            direction = (direction + 1) % DIRECTION_MAX;
            break;
        case LEFT:
            direction = (direction - 1 + DIRECTION_MAX) % DIRECTION_MAX;
            break;
        case ADVANCE:
            switch (direction) {
                case DIRECTION_NORTH:
                    robot->position.y++;
                    break;
                case DIRECTION_EAST:
                    robot->position.x++;
                    break;
                case DIRECTION_SOUTH:
                    robot->position.y--;
                    break;
                case DIRECTION_WEST:
                    robot->position.x--;
                    break;
                default:
                    break;
            }
            break;
    }

    robot->direction = direction;
}

void robot_move(robot_status_t* robot, const char* commands)
{
    size_t num_of_commands = strlen(commands);

    if (num_of_commands <= 0) return;

    for (size_t i = 0; i < num_of_commands; i++) {
        switch (commands[i]) {
            case 'R':
                make_move(robot, RIGHT);
                break;
            case 'L':
                make_move(robot, LEFT);
                break;
            case 'A':
                make_move(robot, ADVANCE);
                break;
        }
    }
}
