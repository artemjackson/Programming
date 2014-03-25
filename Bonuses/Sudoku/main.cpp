#define _XOPEN_SOURCE_EXTENDED

#include <locale.h>
#include <ncurses.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <signal.h>

#include <exception>

#include "field.h"

/* ф-ция обработки сигнала изменения размеров терминала */
void sig_winch(int signo);

/* ф-ция старта ncurses */
void start_ncurses();

/* ф-ция завершения ncurses */
void end_ncurses();

int main()
{
    start_ncurses();

    char press='a';
    bool quit=false;

    /*Об игре*/
    printw("Добро пожаловать в игру судоку!\n");
    printw("Управление: 'w-s-d-a'\n");
    printw("Внести значение в клетку: цифры от 1 до 9\n");
    printw("Удалить значений из клетки: 'c'\n");
    printw("Выход: 'q'\n");
    printw("Нажмите хоть что-нибудь для старта игры :)");
    refresh();
    press=getch();

    Field *game_sudoky;

    while(press!='q')
    {
        try
        {
            game_sudoky = new Field;
        }
        catch(std::exception &e)
        {
            printw("Не удалось создать поле судоку :(\n");
            printw("Нажите любую клавишу для выхода..\n");
            refresh();
            getch();
            exit(1);
        }

        game_sudoky->create();
        game_sudoky->open_cell(41);

        char action;

        while(!quit && !game_sudoky->check_win())
        {
            game_sudoky->print();
            action=getch();

            switch(action)
            {
            case 'w':
                game_sudoky->move_up();
                break;
            case 's':
                game_sudoky->move_down();
                break;
            case 'd':
                game_sudoky->move_right();
                break;
            case 'a':
                game_sudoky->move_left();
                break;
            case 'q':
                quit=true;
                break;
            default:
                game_sudoky->mark(action);
            }
        }
        if(quit)
        {
            printw("\nGoodBye!\n");
            printw("Нажмите любую клавишу для выхода..\n");
            getch();
            delete game_sudoky;
            end_ncurses();
            return 0;
        }

        if(game_sudoky->check_win())
        {
            game_sudoky->print();
            printw("\nСудоку успешно решено!\n");
            printw("Нажмите 'q', для того чтобы выйте или пробел для старта новой игры\n");
            delete game_sudoky;
        }
        press=getch();
        while(press!=' ' && press !='q')
            press=getch();
    }

    end_ncurses();
    return 0;
}

/* ф-ция старта ncurses */
void start_ncurses()
{
    setlocale(LC_ALL, "");

    /*связывам сигнал*/
    signal(SIGWINCH, sig_winch);

    /*инициализация ncurses*/
    initscr();

    /*инициализация палитры цветов*/
    if (!has_colors())
    {
        endwin();
        printf("Цвета не поддерживаются\n");
        exit(1);
    }

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLUE);
}

/* ф-ция обработки сигнала изменения размеров терминала */
void sig_winch(int signo)
{
    winsize size;
    ioctl(fileno(stdout),TIOCGWINSZ,(char*) &(size));
    if(size.ws_row<20 || size.ws_col<20)
    {
        clear();
        printw("Недостаточные размеры терменала\n");
        printw("Следайте размеры окна не менее чем 20х20\n");
        printw("И нажмите пробел\n");
    }
    else
        resizeterm(size.ws_row,size.ws_col);
    refresh();
}

/* ф-ция завершения ncurses */
void end_ncurses()
{
    endwin();
}


