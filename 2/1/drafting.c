int select_trains(Train trains_depot[], Train trains_selected[], int train_count, 
                 bool search_is_long_distance, int desired_time) {
    // Инициализация переменных
    int found = 0;                      // Счётчик найденных поездов
    int min_diff = 1441;                // Максимально возможная разница +1 (24*60=1440)
    int min_idx = -1;                   // Индекс поезда с минимальной разницей

    // Перебор всех поездов в депо
    for (int i = 0; i < train_count; ++i) {
        // Проверка типа поезда (дальний/пригородный)
        if (trains_depot[i].is_long_distance == search_is_long_distance) {
            
            // Расчёт разницы времени
            int dep_time = trains_depot[i].departure_time;
            int diff = dep_time - desired_time;
            
            // Корректировка разницы при переходе через полночь
            if (diff < 0) diff += 1440;  // Пример: 01:00 (60) - 23:00 (1380) → 60-1380 = -1320 → 120
            
            // Поиск минимальной разницы
            if (diff < min_diff) {
                min_diff = diff;        // Обновление минимальной разницы
                min_idx = i;            // Запоминаем индекс поезда (в оригинале ошибка: 'I' вместо 'i')
            }
        }
    }

    // Сохранение результата
    if (min_idx != -1) {               // Если найден подходящий поезд
        trains_selected[found++] = trains_depot[min_idx];  // Копируем поезд в результат
    }

    return found;  // Возвращаем количество найденных поездов (0 или 1)
}
