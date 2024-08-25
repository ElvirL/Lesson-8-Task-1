/*
Задание 1. Реализация имитации аудиоплеера
Что нужно сделать
С помощью классов реализуйте программу имитации работы аудиоплеера. В плеере находится несколько аудиозаписей, доступных для 
воспроизведения. Для них вы должны создать отдельный класс Track. Полями этого класса должны быть: название, дата создания 
(здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.
Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать список доступных записей и нужные для логики работы 
плеера поля.

Пользователь взаимодействует с программой с помощью команд:

• Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение. Воспроизведение симулируется 
с помощью вывода в консоль всей информации о записи. Если произведение какой-то записи уже начато, ничего не происходит.
• Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль. Если запись уже на паузе или не 
воспроизводится вовсе, ничего не происходит.
• Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается случайно, как будто плеер работает в 
режиме shuffle.
• Команда stop прекращает воспроизведение текущей записи, если таковая имеется. Об этом выводится сообщение в консоль. Два раза 
остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.
• Команда exit — выход из программы.

Советы и рекомендации
Забудьте про отдельные глобальные функции и используйте возможности классов и методов по максимуму.
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <string>

class Track{
    std::string name;
    std::tm date_create;
    int duration;

    

    public:
    std::string get_name(){
        return name;
    }

    std::tm get_date_create(){
        return date_create;
    }

    int get_duration(){
        return duration;
    }
};

class Player{
    std::vector<Track> playlist;
    bool audio_play_now = false;
    bool audio_is_pause = true;

    public:
    void play(){
        if (!audio_play_now){
            std::cout << "Введите название аудиозаписи: ";
            std::string name;
            std::cin >> name;
            for (size_t i=0; i<playlist.size(); ++i){
                if (playlist[i].get_name() == name){
                    audio_play_now = true;
                    audio_is_pause = false;
                    std::cout << "Название: " << playlist[i].get_name() << std:: endl;
                    std::tm date_create_track = playlist[i].get_date_create();
                    std::cout << "Дата создания: " << std::put_time(&date_create_track, "%d.%m.%y") << std::endl;
                    std::cout << "Длительность: " << playlist[i].get_duration() << std::endl;
                    break;
                }
                if (i == playlist.size()-1){
                    std::cout << "Аудиозапись не найдена" << std::endl;
                }
            }
        } 
    }

    void pause(){
        if (!audio_is_pause && audio_play_now){
            audio_is_pause = true;
            audio_play_now = false;
            std::cout << "Аудиозапись поставлена на паузу" << std::endl;
        }
    }

    void next(){
        srand(time(0));
        int i = rand() % playlist.size();
    
        std::cout << "Название: " << playlist[i].get_name() << std:: endl;
        std::tm date_create_track = playlist[i].get_date_create();
        std::cout << "Дата создания: " << std::put_time(&date_create_track, "%d.%m.%y") << std::endl;
        std::cout << "Длительность: " << playlist[i].get_duration() << std::endl;
        audio_is_pause = false;
        audio_play_now = true;
    }

    void stop(){
        if (audio_play_now){
            std::cout << "Воспроизведение остановлено" << std::endl;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Russian");
    Player p;

    std::cout << "Введите команду:" << std::endl;
    std::string command;
    std::cin >> command;

    while (command!= "exit"){
        if (command == "play"){
            p.play();
        }
        else if (command == "pause"){
            p.pause();
        }
        else if (command == "stop"){
            p.stop();
        }
        else if (command == "next"){
            p.next();
        }
        std::cout << "Введите команду:" << std::endl;
        std::cin >> command;
    }
}