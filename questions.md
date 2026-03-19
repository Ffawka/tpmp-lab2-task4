
# КОНТРОЛЬНЫЕ ВОПРОСЫ ПО ТЕМЕ (Makefile Style)


# Вопрос 1: Примеры облачных IDE.
cloud_ides:
	"Примеры облачных IDE:"
	"  - Repl.it"
	"  - Gitpod"
	"  - GitHub Codespaces"
	"  - AWS Cloud9"

# Вопрос 2: Подключение репозитория в repl.it.
repl_import:
	"Процесс подключения репозитория в repl.it:"
	"  1. Нажать кнопку '+' (Create new Repl)."
	"  2. Выбрать вкладку 'Import from GitHub'."
	"  3. Вставить URL репозитория."
	"  4. Нажать 'Import from GitHub'."

# Вопрос 3: Что такое «сборка»?
build_definition:
	"Сборка — это процесс преобразования исходного кода"
	"в готовый программный продукт (объектные файлы, исполняемые файлы, библиотеки)."

# Вопрос 4: Утилиты для сборки.
build_utils:
	"Утилиты для сборки:"
	"  - Make (GNU Make)"
	"  - CMake"
	"  - Ninja"
	"  - Apache Ant (Java)"
	"  - Maven (Java)"
	"  - Gradle"
	"  - MSBuild (C#)"

# Вопрос 5: Для чего служит Makefile?
makefile_purpose:
	"Makefile служит для автоматизации сборки проекта,"
	"описания зависимостей между файлами и командами компиляции,"
	"а также для обеспечения минимальной пересборки (только измененных файлов)."

# Вопрос 6: Что такое цель в Makefile? Пример.
target_example:
	"Цель (target) — это конечный результат или действие, которое нужно выполнить."
	"Пример:"
	"\033[0;32mall: main.o utils.o\033[0m\n"
	"\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	"Здесь 'all' — это цель."

# Вопрос 7: Что такое связка в Makefile? Пример.
recipe_example:
	@echo "Связка (recipe) — это набор команд (shell), которые выполняются для достижения цели."
	@echo "Пример:"
	@printf "\033[0;32mclean:\033[0m\n"
	@printf "\t\033[0;33mrm -f *.o program\033[0m\n"
	@printf "\t\033[0;33m@echo 'Очистка завершена'\033[0m\n"
	@echo "Строки с 'rm' и 'echo' — это связка."

# Вопрос 8: Что такое зависимость в Makefile? Пример.
dependency_example:
	@echo "Зависимость (prerequisite) — это файлы или другие цели, которые должны быть"
	@echo "созданы/обновлены до выполнения текущей цели."
	@echo "Пример:"
	@printf "\033[0;32mprogram: main.o utils.o\033[0m\n"
	@printf "\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	@echo "Здесь 'main.o' и 'utils.o' — это зависимости цели 'program'."

# Вопрос 9: Что такое правило в Makefile? Пример.
rule_example:
	@echo "Правило (rule) — это полная конструкция, состоящая из цели,"
	@echo "зависимостей и связки."
	@echo "Пример:"
	@printf "\033[0;32m%.o: %.c\033[0m\n"
	@printf "\t\033[0;33mgcc -c $< -o $@\033[0m\n"
	@echo "Это правило говорит, как собрать любой .o файл из .c файла."

# Вопрос 10: Что такое макроопределение в Makefile? Пример.
macro_definition:
	@echo "Макроопределение (переменная) — это имя, которое хранит строку (путь, флаги, список файлов)."
	@echo "Пример:"
	@printf "\033[0;32mCC = gcc\033[0m\n"
	@printf "\033[0;32mCFLAGS = -Wall -O2\033[0m\n"
	@printf "\033[0;32mTARGET = my_program\033[0m\n"
	@printf "\033[0;32mSRCS = main.c utils.c\033[0m\n"
	@echo "Использование: \$$(CC) \$$(CFLAGS) -o \$$(TARGET) \$$(SRCS)"

# Вопрос 11: Какая связка используется для очистки проекта?
clean_recipe:
	@echo "Традиционная связка для очистки проекта — это цель 'clean'."
	@echo "Пример связки:"
	@printf "\033[0;32mclean:\033[0m\n"
	@printf "\t\033[0;33mrm -rf build/ *.o *.exe program\033[0m\n"
	@printf "\t\033[0;33m@echo 'Проект очищен.'\033[0m\n"

# Вопрос 12: Модель КИС для проектов на языке C?
kis_model:
	@echo "Модель КИС (Компиляция, Исполнение, Сборка) подразумевает разделение этапов:"
	@echo "  - Препроцессинг (обработка #define, #include)"
	@echo "  - Компиляция (получение объектных файлов .o из .c)"
	@echo "  - Линковка (связывание объектных файлов в исполняемый файл)"

# Вопрос 13: Стандарты кодирования?
coding_standards:
	@echo "Стандарты кодирования (например, GNU Style, Google Style) — это свод правил"
	@echo "по оформлению кода (отступы, имена переменных, комментарии)."
	@echo "Рекомендация следовать им обусловлена:"
	@echo "  - Улучшением читаемости кода."
	@echo "  - Облегчением поддержки и ревью."
	@echo "  - Снижением количества ошибок."

# Вопрос 14: Структура проекта согласно модели КИС и правилам сборки?
project_structure:
	@echo "Структура проекта:"
	@echo "  project-root/"
	@echo "  ├── src/         # Исходные файлы (.c)"
	@echo "  ├── include/     # Заголовочные файлы (.h)"
	@echo "  ├── obj/         # Объектные файлы (.o) (создается при сборке)"
	@echo "  ├── bin/         # Исполняемые файлы (создается при сборке)"
	@echo "  ├── Makefile     # Файл сборки"
	@echo "  └── README.md    # Документация"

# Вопрос 15: Что такое Github Actions?
github_actions:
	@echo "GitHub Actions — это платформа CI/CD (Continuous Integration/Continuous Deployment),"
	@echo "встроенная в GitHub. Позволяет автоматизировать задачи: тестирование, сборка,"
	@echo "деплой при пушах, создании Pull Request'ов и т.д."

# Вопрос 16: Что такое workflow в GitHub Actions? Пример.
workflow_example:
	@echo "Workflow — это автоматизированный процесс (один или несколько jobs),"
	@echo "описанный в YAML-файле в папке .github/workflows/."
	@echo "Пример имени файла: \033[0;32mci.yml\033[0m"
	@echo "Пример содержимого (начало):"
	@printf "\033[0;32mname: CI Pipeline\033[0m\n"
	@printf "on: [push]\n"

# Вопрос 17: Что такое event в GitHub Actions? Пример.
event_example:
	@echo "Event — это событие в репозитории, которое запускает workflow."
	@echo "Примеры:"
	@echo "  - push (отправка коммитов)"
	@echo "  - pull_request (создание/обновление PR)"
	@echo "  - schedule (запуск по расписанию)"
	@printf "\033[0mon:\033[0m\n"
	@printf "  \033[0;32mpull_request:\033[0m\n"
	@printf "    branches: [ main ]\n"

# Вопрос 18: Что такое job в GitHub Actions? Пример.
job_example:
	@echo "Job (задача) — это набор шагов (steps), выполняющихся на одном раннере."
	@echo "Пример:"
	@printf "jobs:\n"
	@printf "  \033[0;32mtest:\033[0m\n"
	@printf "    runs-on: ubuntu-latest\n"
	@printf "    steps:\n"
	@printf "      - run: echo 'Тестируем...'\n"

# Вопрос 19: Что такое step в GitHub Actions? Пример.
step_example:
	@echo "Step (шаг) — это отдельная задача внутри job (либо команда shell, либо готовый action)."
	@echo "Пример:"
	@printf "steps:\n"
	@printf "  - \033[0;32mname: Checkout code\033[0m\n"
	@printf "    uses: actions/checkout@v4\n"
	@printf "  - \033[0;32mname: Run tests\033[0m\n"
	@printf "    run: make test\n"

# Вопрос 20: Что такое action в GitHub Actions? Пример.
action_example:
	@echo "Action — это готовый переиспользуемый блок кода (как функция) для выполнения"
	@echo "часто повторяющихся задач (чек-аут, установка ЯП, деплой в облако)."
	@echo "Пример использования (actions/checkout):"
	@printf "steps:\n"
	@printf "  - \033[0;32muses: actions/checkout@v4\033[0m\n"
	@printf "    with:\n"
	@printf "      fetch-depth: 0\n"

# ============================================
# Фиктивная цель для вызова всех ответов (для демонстрации)
# ============================================
all: cloud_ides repl_import build_definition build_utils makefile_purpose \
     target_example recipe_example dependency_example rule_example \
     macro_definition clean_recipe kis_model coding_standards project_structure \
     github_actions workflow_example event_example job_example step_example \
     action_example
	@echo ""
	@echo "=== Все ответы выведены выше. ==="

.PHONY: all cloud_ides repl_import build_definition build_utils makefile_purpose \
        target_example recipe_example dependency_example rule_example \
        macro_definition clean_recipe kis_model coding_standards project_structure \
        github_actions workflow_example event_example job_example step_example \
        action_example
