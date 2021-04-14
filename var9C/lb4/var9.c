#include <stdio.h>
#include <string.h>

struct alphabet {
	char letter;
	int count;
};
//функция проверки символа в массиве структур
//если символ в структуре, возвращается его индекс
//иначе -1
int isIn(char symbol, struct alphabet Alphabet[33], int count) {
	for(int i = 0; i <= count; i++) {
		char textbubble = Alphabet[i].letter;
		if(symbol == textbubble){
			return i;
		}
	}
	return -1;
}
int main() {
	struct alphabet Alphabet[33];
	//массив, в котором будет строка
	char text[80];
	printf("%s\n","Write your text there: ");
	gets(text);

	//создаем указатель, ссылающийся на пробел
	char *space = " ";

	//присваиваем char значение пробела
	char spacebubble = *space;

	//для удобства введем переменную-счетчик текущего незаполненного
	//индекса структуры
	int currentIndex = 0;

	for (int i = 0; text[i] != '.'; i++) {
		char textbubble = text[i];
		//сравниваем элемент строки с пробелом (через пузырёк)
		if (textbubble != spacebubble){
			//проверяем есть ли символ в структуре
			if (isIn(textbubble, Alphabet, currentIndex) != -1) {
				//если есть прибавляем счетчик
				Alphabet[isIn(textbubble, Alphabet, currentIndex)].count++;
			} else {
				//если нет, присваиваем его к текущему пустому значению
				Alphabet[currentIndex].letter = textbubble;
				Alphabet[currentIndex].count++;
				currentIndex++;
			}
		}
	}

	//выведем структуру с количеством повторений символа
	for (int i = 0; i < currentIndex; i++) {
		// printf("%c", Alphabet[i].letter);
		// printf("%d\n", Alphabet[i].count);
		printf("%s%c%s%d%s\n", "Symbol: '", Alphabet[i].letter,
				"' appears in the text ", Alphabet[i].count," times");
	}
	return 0;
}
