#include <iostream>

#include "..\AllClassesTVForRacing\Camel.h"
#include "..\AllClassesTVForRacing\CamelSpidrun.h"
#include "..\AllClassesTVForRacing\Kentaur.h"
#include "..\AllClassesTVForRacing\BootAllvechicle.h"
#include "..\AllClassesTVForRacing\CarpetAirplane.h"
#include "..\AllClassesTVForRacing\Eagle.h"
#include "..\AllClassesTVForRacing\Broom.h"

//class GroundTransport {
//public:
//    GroundTransport() {
//        _speedMove = 0;
//        _timeMoveToRelax = 0;
//    }
//    //virtual double DurationRelax(int& counter) = 0;//это чистая виртуальн. функция - она не имеет реализации, компелятор проверяет переопределение, также нельзя создать объект этого класса
//    virtual double DurationRelax(int& counter) {
//        return 0;
//    }
//    int getSpeedMove() {
//        return _speedMove;
//    }
//    int getTimeMoveToRelax() {
//        return _timeMoveToRelax;
//    }
//protected:
//    int _speedMove;
//    int _timeMoveToRelax;
//};
//
//class Camel : public GroundTransport {  
//public:
//    Camel() {
//        _speedMove = 10;
//        _timeMoveToRelax = 30;
//    }
//    double DurationRelax(int& counter)override {
//        counter++;
//        if (counter == 1) {
//            return 5;
//        }
//        else {
//            return 8;
//        }
//    }
//};
//class CamelSpidrun : public GroundTransport {
//public:
//    CamelSpidrun() {
//        _speedMove = 40;
//        _timeMoveToRelax = 10;
//    }
//    double DurationRelax(int& counter)override {
//        counter++;
//        if (counter == 1) {
//            return 5;
//        }
//        else if (counter == 2) {
//            return 6.5;
//        }
//        else {
//            return 8;
//        }
//    }
//};
//class Kentaur : public GroundTransport {
//public:
//    Kentaur() {
//        _speedMove = 15;
//        _timeMoveToRelax = 8;
//    }
//    double DurationRelax(int &counter)override {
//        counter++;
//        return 2;
//    }
//};
//class BootAllvechicle : public GroundTransport {
//public:
//    BootAllvechicle() {
//        _speedMove = 6;
//        _timeMoveToRelax = 60;
//    }
//    double DurationRelax(int& counter)override {
//        counter++;
//        if (counter == 1) {
//            return 10;
//        }
//        else {
//            return 5;
//        }
//    }
//};
//
//
//class AirTransport {
//public:
//    AirTransport(){
//        _speedMove = 0;
//    }
//    virtual int CoefficientSortsDistance(int distance) {
//        return 0;
//    }
//    int getSpeedMove() {
//        return _speedMove;
//    }
//protected:
//    int _speedMove;
//};
//class CarpetAirplane : public AirTransport {
//public:
//    CarpetAirplane() {
//        _speedMove = 10;
//    }
//    int CoefficientSortsDistance(int distance)override {
//        if (distance < 1000) {
//            return 0;//без сокращения
//        }
//        else if(distance < 5000) {
//            return 3;//%
//        }
//        else if(distance < 10000) {
//            return 10;
//        }
//        else if(distance >= 10000) {
//            return 5;
//        }
//    }
//};
//class Eagle : public AirTransport {
//public:
//    Eagle() {
//        _speedMove = 8;
//    }
//    int CoefficientSortsDistance(int distance)override {
//        return 6;
//    }
//};
//class Broom : public AirTransport {
//public:
//    Broom() {
//        _speedMove = 20;
//    }
//    int CoefficientSortsDistance(int distance)override {
//        if (distance < 50000) {
//            double temp = distance / 1000;
//            int temp2 = static_cast<int>(temp);
//            return temp2;
//        }
//        else {
//            return 50;//не зависимо от расстояния больше 50% не будет
//        }
//    }
//};

double groundRace(int numberTS, int distance) {//ground function
    GroundTransport* GT = nullptr;

    if (numberTS == 1) {
        Camel* objCamel = new Camel;
        GT = objCamel;
    }
    else if (numberTS == 2) {
        CamelSpidrun* objCamelSpidrun = new CamelSpidrun;
        GT = objCamelSpidrun;
    }
    else if (numberTS == 3) {
        Kentaur* objKentaur = new Kentaur;
        GT = objKentaur;
    }
    else if (numberTS == 4) {
        BootAllvechicle* objBootAllvechicle = new BootAllvechicle;
        GT = objBootAllvechicle;
    }

    int timeMovingWay = 0, countRelax = 0;
    double timeRelaxMultCount = 0;
    timeMovingWay = distance / GT->getSpeedMove();//вычесление
    countRelax = static_cast<int>(timeMovingWay / GT->getTimeMoveToRelax());
    for (int counter = 0; counter < countRelax; )
    {
        timeRelaxMultCount = +GT->DurationRelax(counter);
    }
    delete GT;
    return timeMovingWay + timeRelaxMultCount;

}
double airRace(int numberTS, int distance) {//air function
    AirTransport* AT = new AirTransport;

    if (numberTS == 5) {
        CarpetAirplane* objCarpetAirplane = nullptr;
        AT = objCarpetAirplane;
    }
    else if (numberTS == 6) {
        Eagle* objEagle = new Eagle;
        AT = objEagle;
    }
    else if (numberTS == 7) {
        Broom* objBroom = new Broom;
        AT = objBroom;
    }

    int durationWithKoeffic = distance * (1 - (AT->CoefficientSortsDistance(distance) / 100));
    int tempSpeedMove = AT->getSpeedMove();
    delete AT;
    return durationWithKoeffic / tempSpeedMove;
}



int main()
{
    while (true) {
        setlocale(LC_ALL, "Rus");
        int distance, typeRiver, action;
        std::string arr[10];
        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl
            << "1. Гонка для наземного транспорта" << std::endl
            << "2. Гонка для воздушного транспорта" << std::endl
            << "3. Гонка для наземного и воздушного транспорта" << std::endl
            << "Выберите тип гонки: ";
        std::cin >> typeRiver;
        if (typeRiver != 1 && typeRiver != 2 && typeRiver != 3) {
            while (true) {
                std::cout << "Такой гонки не существует! Введите значение правельно 1, 2 или 3: " << std::endl;
                std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl
                    << "1. Гонка для наземного транспорта" << std::endl
                    << "2. Гонка для воздушного транспорта" << std::endl
                    << "3. Гонка для наземного и воздушного транспорта" << std::endl
                    << "Выберите тип гонки: ";
                std::cin >> typeRiver;
                if (typeRiver == 1 || typeRiver == 2 || typeRiver == 3) {
                    break;
                }
            }
        }

        std::cout << "Укажите длину дистанции (Должна быть положительна): " << std::endl;
        std::cin >> distance;
		while (distance < 0) {
			std::cout << "Дистанция не может быть отрицательной, введите еще раз: " << std::endl;
			std::cin >> distance;
		}
        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
        std::cout << "1. Зарегистрировать транспорт" << std::endl
            << "Выберете действие: ";
        std::cin >> action;
        if (action != 1) {
            std::cout << "Вы ввели не ту комманду" << std::endl;
            while (true) {
                std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
                std::cout << "1. Зарегистрировать транспорт" << std::endl
                    << "Выберете действие: ";
                std::cin >> action;
                if (action == 1)
                {
                    break;
                }
                std::cout << "Вы ввели не ту комманду" << std::endl;
            }
        }

        int countTS = 0;

		while (true) {

			std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl
				<< "1. Верблюд" << std::endl << "2. Верблюд-быстроход" << std::endl << "3. Кентавр" << std::endl
				<< "4. Ботинки-вездеходы" << std::endl
				<< "5. Ковер-самолет" << std::endl << "6. Орел" << std::endl << "7. Метла" << std::endl
				<< "0. Закончить регистрацию" << std::endl
				<< "Выберете транспорт или 0 для окончания регистрации: ";
			std::cin >> action;

			if (typeRiver == 1)//проверка какой тип гонки выбрали для запрета
			{
				if (action > 0 && action < 5 || action == 0) {
					//идем дальше
				}
				else if (action > 4 && action < 8) {
					std::cout << "Данный тип транспорта не может учавствовать в гонке, выберете наземный транспорт" << std::endl;
					continue;
				}
				else {
                    std::cout << "Такого ТС нет! Введите значение правельно." << std::endl;
                    continue;
				}
			}
			else if (typeRiver == 2) {
				if (action > 4 && action < 8 || action == 0) {
					//идем дальше
				}
				else if (action > 0 && action < 5) {
					std::cout << "Данный тип транспорта не может учавствовать в гонке, выберете воздушный транспорт" << std::endl;
					continue;
				}
				else {
					std::cout << "Такого ТС нет! Введите значение правельно." << std::endl;
					continue;
				}
			}
			else {
				if (action > -1 && action < 8) {
					//идем дальше
				}
				else {
					std::cout << "Такого ТС нет! Введите значение правельно." << std::endl;
					continue;
				}
			}

            bool alreadyHere = false;
			if (action == 1) {//кладем в массив тот транспорт который выбрали и который соответствует типу гонки и проверяем есть ли уже это ТС в массиве
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Верблюд")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Верблюд уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Верблюд";
                    countTS++;
                }
			}
			else if (action == 2) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Верблюд-быстроход")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Верблюд-быстроход уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Верблюд-быстроход";
                    countTS++;
                }
			}
			else if (action == 3) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Кентавр")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Кентавр уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Кентавр";
                    countTS++;
                }
			}
			else if (action == 4) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Ботинки-вездеходы")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Ботинки-вездеходы уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Ботинки-вездеходы";
                    countTS++;
                }
			}
			else if (action == 5) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Ковер-самолет")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Ковер-самолет уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Ковер-самолет";
                    countTS++;
                }
			}
			else if (action == 6) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Орел")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Орел уже зарегестрирован, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Орел";
                    countTS++;
                }
			}
			else if (action == 7) {
                for (int i = 0; i < countTS; i++)
                {
                    if (arr[i] == "Метла")
                    {
                        alreadyHere = true;
                        break;
                    }
                }
                if (alreadyHere == true) {
                    std::cout << "Метла уже зарегестрирована, вы не можете сделать это повторно" << std::endl;
                }
                else {
                    arr[countTS] = "Метла";
                    countTS++;
                }
			}

			

			if (countTS > 0) {
				std::cout << "Вы зарегестрировали: ";
				for (int i = 0; countTS > i; i++) {
					std::cout << arr[i];
					if (countTS > i - 2) {
						std::cout << ", ";
					}
				}
				std::cout << std::endl;
			}


			if (action == 0) {
				if (countTS < 2) {
					std::cout << "Вы зарегистрировали меньше 2-х ТС" << std::endl;
					continue;
				}
				int action2 = 0;
				std::cout << std::endl;
				std::cout << "1. Зарегистрировать транспорт" << std::endl
					<< "2. Начать гонку" << std::endl
					<< "Выберете действие: ";
				std::cin >> action2;
				if (action2 == 1) {
					continue;
				}
				else if (action2 == 2) {
					break;
				}
				else {//если пользователь ввел не существующую комманду - спарашиваем до тех пор пока не введет правельно (:
                    std::cout << "Не могу распознать команду" << std::endl;
                    while (true) {
                        std::cout << "1. Зарегистрировать транспорт" << std::endl
                            << "2. Начать гонку" << std::endl
                            << "Выберете действие: ";
                        std::cin >> action2;
                        if (action2 > 0 && action2 < 3) {
                            break;
                        }
                        else {
                            std::cout << "Не могу распознать команду" << std::endl;
                            continue;
                        }
                    }
                    if (action2 == 1) {
                        continue;
                    }
                    else if (action2 == 2) {
                        break;
                    }
					
				}
			}
		}
		///логика просчета победителя.....
        double totalTime;
        double arrTotalTime[7];

        if (typeRiver == 1)//проверка какой тип гонки выбрали для запрета
        {
            for (int i = 0; i < countTS; i++)
            {
                if (arr[i] == "Верблюд") {
                    totalTime = groundRace(1, distance);
                }
                else if (arr[i] == "Верблюд-быстроход") {
                    totalTime = groundRace(2, distance);
                }
                else if (arr[i] == "Кентавр") {
                    totalTime = groundRace(3, distance);
                }
                else if (arr[i] == "Ботинки-вездеходы") {
                    totalTime = groundRace(4, distance);
                }
                arrTotalTime[i] = totalTime;
            }
        }
		else if (typeRiver == 2) {
			for (int i = 0; i < countTS; i++)
			{
				if (arr[i] == "Ковер-самолет") {
					totalTime = airRace(5, distance);
				}
				else if (arr[i] == "Орел") {
					totalTime = airRace(6, distance);
				}
				else if (arr[i] == "Метла") {
					totalTime = airRace(7, distance);
				}
                arrTotalTime[i] = totalTime;
			}
		}
        else {//третий тип гонки

            for (int i = 0; i < countTS; i++)
            {

                if (arr[i] == "Верблюд") {
                    totalTime = groundRace(1, distance);
                }
                else if (arr[i] == "Верблюд-быстроход") {
                    totalTime = groundRace(2, distance);
                }
                else if (arr[i] == "Кентавр") {
                    totalTime = groundRace(3, distance);
                }
                else if (arr[i] == "Ботинки-вездеходы") {
                    totalTime = groundRace(4, distance);
                }
                else if (arr[i] == "Ковер-самолет") {
                    totalTime = airRace(5, distance);
                }
                else if (arr[i] == "Орел") {
                    totalTime = airRace(6, distance);
                }
                else if (arr[i] == "Метла") {
                    totalTime = airRace(7, distance);
                }
                arrTotalTime[i] = totalTime;
            }
        }

        std::cout << "Результаты гонки" << std::endl;
        for (int j = 0; j < countTS - 1; j++)//сортировка по возрастанию 2-х массивов
        {
            double temp;
            std::string tempStr;
            for (int i = 0; i < countTS - 1; i++)
            {
                if (arrTotalTime[i] > arrTotalTime[i + 1]) {

                    temp = arrTotalTime[i];
                    arrTotalTime[i] = arrTotalTime[i + 1];
                    arrTotalTime[i + 1] = temp;
                    tempStr = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tempStr;
                }
            }
        }
        for (int i = 0; i < countTS; i++)
        {
            double temp = arrTotalTime[i];
            std::cout << i + 1 << ". " << arr[i] << ". Время: " << temp << std::endl;
        }

        std::cout << std::endl;
        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action;
        if (action == 1)
        {
            continue;
        }
        else if (action == 2) {
            break;
        }
        else {
            std::cout << "Вы ввели не правельную команду!" << std::endl;
            break;
        }
	}
    return 0;
}
