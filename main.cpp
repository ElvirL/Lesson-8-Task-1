/*
������� 1. ���������� �������� �����������
��� ����� �������
� ������� ������� ���������� ��������� �������� ������ �����������. � ������ ��������� ��������� ������������, ��������� ��� 
���������������. ��� ��� �� ������ ������� ��������� ����� Track. ������ ����� ������ ������ ����: ��������, ���� �������� 
(����� �� ������ ������������ ��� std::tm) � ����������������� ������ � ��������.
��� ����� ���� ���������� � ������� ������. ������ �� ������ ��������� ������ ��������� ������� � ������ ��� ������ ������ 
������ ����.

������������ ��������������� � ���������� � ������� ������:

� ������� play ����������� � ������������ �������� ������ ��� ��������������� � �������� � ���������������. ��������������� ������������ 
� ������� ������ � ������� ���� ���������� � ������. ���� ������������ �����-�� ������ ��� ������, ������ �� ����������.
� ������� pause. ������ ������ �� �����, � ��� ������� ��������������� ��������� � �������. ���� ������ ��� �� ����� ��� �� 
��������������� �����, ������ �� ����������.
� ������� next ��������� � ��������� ������ ��� ���������������. ������ ��� ���� ���������� ��������, ��� ����� ����� �������� � 
������ shuffle.
� ������� stop ���������� ��������������� ������� ������, ���� ������� �������. �� ���� ��������� ��������� � �������. ��� ���� 
���������� ��������������� ����������, ��� ��� ������� ������ ����������� ������ � ������ ������.
� ������� exit � ����� �� ���������.

������ � ������������
�������� ��� ��������� ���������� ������� � ����������� ����������� ������� � ������� �� ���������.
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
            std::cout << "������� �������� �����������: ";
            std::string name;
            std::cin >> name;
            for (size_t i=0; i<playlist.size(); ++i){
                if (playlist[i].get_name() == name){
                    audio_play_now = true;
                    audio_is_pause = false;
                    std::cout << "��������: " << playlist[i].get_name() << std:: endl;
                    std::tm date_create_track = playlist[i].get_date_create();
                    std::cout << "���� ��������: " << std::put_time(&date_create_track, "%d.%m.%y") << std::endl;
                    std::cout << "������������: " << playlist[i].get_duration() << std::endl;
                    break;
                }
                if (i == playlist.size()-1){
                    std::cout << "����������� �� �������" << std::endl;
                }
            }
        } 
    }

    void pause(){
        if (!audio_is_pause && audio_play_now){
            audio_is_pause = true;
            audio_play_now = false;
            std::cout << "����������� ���������� �� �����" << std::endl;
        }
    }

    void next(){
        srand(time(0));
        int i = rand() % playlist.size();
    
        std::cout << "��������: " << playlist[i].get_name() << std:: endl;
        std::tm date_create_track = playlist[i].get_date_create();
        std::cout << "���� ��������: " << std::put_time(&date_create_track, "%d.%m.%y") << std::endl;
        std::cout << "������������: " << playlist[i].get_duration() << std::endl;
        audio_is_pause = false;
        audio_play_now = true;
    }

    void stop(){
        if (audio_play_now){
            std::cout << "��������������� �����������" << std::endl;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Russian");
    Player p;

    std::cout << "������� �������:" << std::endl;
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
        std::cout << "������� �������:" << std::endl;
        std::cin >> command;
    }
}