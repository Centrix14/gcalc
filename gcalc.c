#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gtk/gtk.h>

/*
 * gcalc - graphical calculator v0.6.2
 * by Centrix
 * 03.10.2019
 */

void num_bttn_click(GtkWidget *bttn, gpointer label);
void c_bttn_click(GtkWidget *bttn, gpointer label);
void op_bttn_click(GtkWidget *bttn, gpointer data);
void eq_bttn_click(GtkWidget *bttn, gpointer label);
void tn1_bttn_click(GtkWidget *bttn, gpointer data);
void tn2_bttn_click(GtkWidget *bttn, gpointer data);
void r_bttn_click(GtkWidget *bttn, gpointer label);
void w_bttn_click(GtkWidget *bttn, gpointer label);
void fp_bttn_click(GtkWidget *bttn, gpointer label);
void quick_op_bttn_click(GtkWidget *bttn, gpointer label);
void del_bttn_click(GtkWidget *bttn, gpointer label);
void af_bttn_click(GtkWidget *bttn, gpointer label);

double num1 = 0, num2 = 0;
double *num_ptr = &num1;
int op = 0, whole = 10, point = 1;
GtkWidget *bttn_stack_mode;

enum _ops { sum, subt, mult, divs, powr, srt, inv, dbm, sino, coso, tano, asino, acoso, atano, sinho, cosho, tanho, logo, log10o, expo, modo, ceilo, flooro, pio, eo, facto, delo };

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *bttn_1, *bttn_2, *bttn_3, *bttn_4, *bttn_5, *bttn_6, *bttn_7, *bttn_8, *bttn_9, *bttn_0;
	GtkWidget *bttn_sum, *bttn_subt, *bttn_mult, *bttn_div, *bttn_eq, *bttn_c, *bttn_pow, *bttn_sqrt, *bttn_inv, *bttn_dbm;
	GtkWidget *bttn_cos, *bttn_sin, *bttn_tan, *bttn_acos, *bttn_asin, *bttn_atan, *bttn_cosh, *bttn_sinh, *bttn_tanh, *bttn_log, *bttn_log10;
	GtkWidget *bttn_exp, *bttn_ceil, *bttn_mod, *bttn_floor, *bttn_fp, *bttn_pi, *bttn_e, *bttn_fact;
	GtkWidget *bttn_tn1, *bttn_tn2, *bttn_r, *bttn_w, *bttn_del, *bttn_adv_features;
	GtkWidget *answer;
	GtkWidget *num_pad, *top_pad, *row1, *row2, *row3, *row4, *row5, *row6, *row7, *row8, *row9, *row10, *row11, *mbox;

	gtk_init(&argc, &argv);

	// Создаём окно
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "gcalc");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);

	// При закрытии окна программа завершается
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// Текст содержащий ответ
	answer = gtk_label_new("0");

	// Кнопки ввода числа
	bttn_1 = gtk_button_new_with_label("1");
	bttn_2 = gtk_button_new_with_label("2");
	bttn_3 = gtk_button_new_with_label("3");
	bttn_4 = gtk_button_new_with_label("4");
	bttn_5 = gtk_button_new_with_label("5");
	bttn_6 = gtk_button_new_with_label("6");
	bttn_7 = gtk_button_new_with_label("7");
	bttn_8 = gtk_button_new_with_label("8");
	bttn_9 = gtk_button_new_with_label("9");
	bttn_0 = gtk_button_new_with_label("0");

	// Кнопки арифметических операций
	bttn_sum = gtk_button_new_with_label("+");
	bttn_subt = gtk_button_new_with_label("-");
	bttn_mult = gtk_button_new_with_label("x");
	bttn_div = gtk_button_new_with_label("/");

	// Служебные кнопки
	bttn_eq = gtk_button_new_with_label("=");
	bttn_c = gtk_button_new_with_label("C");

	// Дополнительные кнопки
	bttn_pow = gtk_button_new_with_label("^");
	bttn_sqrt = gtk_button_new_with_label("R");
	bttn_inv = gtk_button_new_with_label("I");
	bttn_dbm = gtk_button_new_with_label("%");
	bttn_fact = gtk_button_new_with_label("!");
	bttn_pi = gtk_button_new_with_label("Pi");
	bttn_e = gtk_button_new_with_label("E");

	// Основные тригонометрические функции
	bttn_sin = gtk_button_new_with_label("sin");
	bttn_cos = gtk_button_new_with_label("cos");
	bttn_tan = gtk_button_new_with_label("tan");

	// Арк- версии тригонометрических функций
	bttn_asin = gtk_button_new_with_label("asin");
	bttn_acos = gtk_button_new_with_label("acos");
	bttn_atan = gtk_button_new_with_label("atan");

	// Гиперболические функции
	bttn_sinh = gtk_button_new_with_label("sinh");
	bttn_cosh = gtk_button_new_with_label("cosh");
	bttn_tanh = gtk_button_new_with_label("tanh");

	// Логарифмы и экспонента
	bttn_log = gtk_button_new_with_label("log");
	bttn_log10 = gtk_button_new_with_label("lg");
	bttn_exp = gtk_button_new_with_label("exp");

	// Модуль и округление
	bttn_ceil = gtk_button_new_with_label("R>");
	bttn_mod = gtk_button_new_with_label("|n|");
	bttn_floor = gtk_button_new_with_label("R<");

	// Кнопка создания десятичной точки
	bttn_fp = gtk_button_new_with_label(",");

	// Кнопка расширенных возможностей
	bttn_adv_features = gtk_button_new_with_label("AF");

	// Специальные кнопки
	bttn_tn1 = gtk_button_new_with_label("TN1");
	bttn_tn2 = gtk_button_new_with_label("TN2");
	bttn_r = gtk_button_new_with_label("BR");
	bttn_w = gtk_button_new_with_label("BW");
	bttn_del = gtk_button_new_with_label("<x");

	// Переключать для перехода в режим стека
	bttn_stack_mode = gtk_toggle_button_new_with_label("SM");

	// Подключаем кнопки цифр к функции num_bttn_click
	g_signal_connect(G_OBJECT(bttn_1), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_2), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_3), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_4), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_5), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_6), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_7), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_8), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_9), "clicked", G_CALLBACK(num_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_0), "clicked", G_CALLBACK(num_bttn_click), answer);

	// Связываем кнопку C с функцией c_bttn_click
	g_signal_connect(G_OBJECT(bttn_c), "clicked", G_CALLBACK(c_bttn_click), answer);

	// Связываем кнопки операций с функцией op_bttn_click
	g_signal_connect(G_OBJECT(bttn_sum), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_subt), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_mult), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_div), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_pow), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_sqrt), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_dbm), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_sin), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_cos), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_tan), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_asin), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_acos), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_atan), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_sinh), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_cosh), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_tanh), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_log), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_log10), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_exp), "clicked", G_CALLBACK(op_bttn_click), NULL);

	// Подключаем быстрые кнопки
	g_signal_connect(G_OBJECT(bttn_inv), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_mod), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_ceil), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_floor), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_fact), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_pi), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_e), "clicked", G_CALLBACK(quick_op_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_del), "clicked", G_CALLBACK(quick_op_bttn_click), answer);

	// Связываем кнопку = с функцией eq_bttn_click
	g_signal_connect(G_OBJECT(bttn_eq), "clicked", G_CALLBACK(eq_bttn_click), answer);

	// Ввод запятой для десятичной дроби
	g_signal_connect(G_OBJECT(bttn_fp), "clicked", G_CALLBACK(fp_bttn_click), answer);

	// Стирание самой правой цифры
	g_signal_connect(G_OBJECT(bttn_del), "clicked", G_CALLBACK(del_bttn_click), answer);

	g_signal_connect(G_OBJECT(bttn_adv_features), "clicked", G_CALLBACK(af_bttn_click), NULL);

	// Связывакм кнопки tn1, tn2, r, w с функциями tn1_bttn_click, tn2_bttn_click, r_bttn_click, w_bttn_click
	g_signal_connect(G_OBJECT(bttn_tn1), "clicked", G_CALLBACK(tn1_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_tn2), "clicked", G_CALLBACK(tn2_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_r), "clicked", G_CALLBACK(r_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_w), "clicked", G_CALLBACK(w_bttn_click), answer);

	// Выключаем переключатель
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bttn_stack_mode), FALSE);
	// Делаем текст выбираемым
	gtk_label_set_selectable(GTK_LABEL(answer), TRUE);

	// Ряды кнопок
	row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row7 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row8 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row9 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row10 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row11 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

	// Первый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row1), bttn_1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row1), bttn_2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row1), bttn_3, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row1), bttn_sum, TRUE, FALSE, 5);

	// Второй ряд кнопок
	gtk_box_pack_start(GTK_BOX(row2), bttn_4, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row2), bttn_5, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row2), bttn_6, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row2), bttn_subt, TRUE, FALSE, 5);

	// Третий ряд кнопок
	gtk_box_pack_start(GTK_BOX(row3), bttn_7, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row3), bttn_8, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row3), bttn_9, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row3), bttn_mult, TRUE, FALSE, 5);

	// Четвёртый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row4), bttn_0, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row4), bttn_div, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row4), bttn_eq, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row4), bttn_c, TRUE, FALSE, 5);

	// Пятый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row5), bttn_pow, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row5), bttn_sqrt, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row5), bttn_inv, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row5), bttn_dbm, TRUE, FALSE, 5);

	// Шестой ряд кнопок
	gtk_box_pack_start(GTK_BOX(row6), bttn_sin, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_cos, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_tan, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_asin, TRUE, FALSE, 5);

	// Седьмой ряд кнопок
	gtk_box_pack_start(GTK_BOX(row7), bttn_acos, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row7), bttn_atan, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row7), bttn_sinh, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row7), bttn_cosh, TRUE, FALSE, 5);

	// Восьмой ряд кнопок
	gtk_box_pack_start(GTK_BOX(row8), bttn_tanh, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row8), bttn_log, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row8), bttn_log10, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row8), bttn_exp, TRUE, FALSE, 5);

	// Девятый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row9), bttn_mod, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row9), bttn_ceil, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row9), bttn_floor, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row9), bttn_fp, TRUE, FALSE, 5);

	// Десятый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row10), bttn_fact, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row10), bttn_pi, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row10), bttn_e, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row10), bttn_adv_features, TRUE, FALSE, 5);

	// Одиннадцатый ряд кнопок
	gtk_box_pack_start(GTK_BOX(row11), bttn_tn1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row11), bttn_tn2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row11), bttn_r, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row11), bttn_w, TRUE, FALSE, 5);

	// num_pad - панель ввода чисел и операций
	num_pad = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// Добавляем ряды кнопок в num_pad
	gtk_box_pack_start(GTK_BOX(num_pad), row1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row3, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row4, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row5, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row6, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row7, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row8, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row9, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row10, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row11, TRUE, FALSE, 5);

	top_pad = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_box_pack_start(GTK_BOX(top_pad), bttn_stack_mode, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(top_pad), answer, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(top_pad), bttn_del, TRUE, FALSE, 5);

	// mbox - основной контейнер
	mbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// Добавляем num_pad и top_pad в mbox
	gtk_box_pack_start(GTK_BOX(mbox), top_pad, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(mbox), num_pad, TRUE, FALSE, 5);

	// Добавляем основной контейнер к окну
	gtk_container_add(GTK_CONTAINER(window), mbox);
	gtk_widget_show_all(window);

	gtk_main(); 
	return 0;
}

// Обрабатывает нажатие кнопки-цифры
void num_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];
	double ipart = 0, fpart = 0;

	*num_ptr = *num_ptr * whole + atof( gtk_button_get_label(GTK_BUTTON(bttn)) ) / point;

	fpart = modf(*num_ptr, &ipart);
	if ( fpart == 0.0 )
		sprintf(tmp, "%d", (int)*num_ptr);
	else
		sprintf(tmp, "%f", *num_ptr);
	gtk_label_set_text(GTK_LABEL(label), tmp);
	if ( point > 1 ) point *= 10;
}

// Обрабатывает нажатие кнопки C
void c_bttn_click(GtkWidget *bttn, gpointer label) {
	*num_ptr = 0;
	whole = 10;
	point = 1;
	gtk_label_set_text(GTK_LABEL(label), "0");
}

// Производит поиск элемента elm, в массиве list с длинной range
int find(char *list[], const char *elm, int range) {
	for (int i = 0; i < range; i++) {
		if ( !strcmp(list[i], elm) ) return i;
	}
	return -1;
}

// Обрабатывает нажатие кнопки-операции
void op_bttn_click(GtkWidget *bttn, gpointer data) {
	char *operations[] = {"+", "-", "x", "/", "^", "R", "I", "%", "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "log", "lg", "exp", "|n|", "cl", "fl"};
	num2 = 0;
	whole = 10;
	point = 1;
	num_ptr = &num2;
	op = find( operations, gtk_button_get_label(GTK_BUTTON(bttn)), 23 );
}

// Нажатие =
void eq_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[512] = "?";

	switch (op) {
		case sum:
			sprintf(tmp, "%f", num1+num2);
			break;
		case subt:
			sprintf(tmp, "%f", num1-num2);
			break;
		case mult:
			sprintf(tmp, "%f", num1*num2);
			break;
		case divs:
			if ( num2 != 0 )
				sprintf(tmp, "%f", num1/num2);
			else {
				gtk_label_set_text(GTK_LABEL(label), "The surgery doesn't make sense.");
				return;
			}
			break;
		case powr:
			sprintf(tmp, "%f", pow(num1, num2));
			break;	
		case srt:
			sprintf(tmp, "%f", sqrt( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case dbm:
			sprintf(tmp, "%f", (int)num1 % (int)num2);
			break;
		case sino:
			sprintf(tmp, "%e", sin( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case coso:
			sprintf(tmp, "%e", cos( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case tano:
			sprintf(tmp, "%e", tan( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case asino:
			sprintf(tmp, "%e", asin( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case acoso:
			sprintf(tmp, "%e", acos( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case atano:
			sprintf(tmp, "%e", atan( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case sinho:
			sprintf(tmp, "%e", sinh( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case cosho:
			sprintf(tmp, "%e", cosh( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case tanho:
			sprintf(tmp, "%e", tanh( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case logo:
			sprintf(tmp, "%e", log( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case log10o:
			sprintf(tmp, "%e", log10( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case expo:
			sprintf(tmp, "%e", exp( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
	}

	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bttn_stack_mode)) == TRUE ) {
		num1 = atof(tmp);
		num_ptr = &num2;
	}

	gtk_label_set_text(GTK_LABEL(label), tmp);
}

// Кнопка TN1
void tn1_bttn_click(GtkWidget *bttn, gpointer data) {
	num_ptr = &num1;
}

// Кнопка TN2
void tn2_bttn_click(GtkWidget *bttn, gpointer data) {
	num_ptr = &num2;
}

// Кнопка BR
void r_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];
	sprintf(tmp, "%f", *num_ptr);
	gtk_label_set_text(GTK_LABEL(label), tmp);
}

// Кнопка BW
void w_bttn_click(GtkWidget *bttn, gpointer label) {
	*num_ptr = atof( gtk_label_get_text(GTK_LABEL(label)) );
}

// Кнопка запятой
void fp_bttn_click(GtkWidget *bttn, gpointer label) {
	whole = 1;
	point = 10;
}

int factorial(int n) {
	if ( !n ) return 1;
	return n*factorial(n-1);
}

// Обрабатывает специальные кнопки быстрых операций
void quick_op_bttn_click(GtkWidget *bttn, gpointer label) {
	char *operations[] = {"I", "|n|", "cl", "fl", "Pi", "E", "!"};
	char tmp[256] = "?";

	switch (find(operations, gtk_button_get_label(GTK_BUTTON(bttn)), 7)) {
		case 0:
			sprintf(tmp, "%f", -atof(gtk_label_get_text(GTK_LABEL(label))));
			break;
		case 1:
			sprintf(tmp, "%f", fabs( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case 2:
			sprintf(tmp, "%f", ceil( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case 3:
			sprintf(tmp, "%f", floor( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case 4:
			sprintf(tmp, "3.1415926535");
			break;
		case 5:
			sprintf(tmp, "2.7182818284");
			break;
		case 6:
			sprintf(tmp, "%d", factorial( atoi(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
	}

	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bttn_stack_mode)) == TRUE ) {
		num1 = atof(tmp);
		num_ptr = &num2;
	}

	gtk_label_set_text(GTK_LABEL(label), tmp);
}

void del_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];

	if ( point == 1 ) {
		*num_ptr = ( *num_ptr-((int)*num_ptr % 10) ) / 10;
		sprintf(tmp, "%d", (int)*num_ptr);
	}
	else {
		point /= 10;
		*num_ptr = ( ( *num_ptr * point ) - ( (int)(*num_ptr * point) % 10 ) ) / point;
		sprintf(tmp, "%f", *num_ptr);
	}
	gtk_label_set_text(GTK_LABEL(label), tmp);
}

void af_bttn_click(GtkWidget *bttn, gpointer data) {
	GtkWidget *dialog, *res, *bttn_convert, *entry_value_from, *entry_value_to, *cb_from, *cb_to;
	GtkWidget *from_box, *to_box, *res_box, *content_box, *main_box;

	dialog = gtk_dialog_new_with_buttons("Advanced features", NULL, (GtkDialogFlags)NULL, NULL);

	content_box = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	entry_value_from = gtk_entry_new();
	entry_value_to = gtk_entry_new();

	res = gtk_label_new("0");
	bttn_convert = gtk_button_new_with_label("Convert");

	cb_from = gtk_combo_box_text_new();
	cb_to = gtk_combo_box_text_new();

	gtk_label_set_selectable(GTK_LABEL(res), TRUE);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_from), "1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_to), "2");

	from_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	to_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	res_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

	gtk_box_pack_start(GTK_BOX(from_box), cb_from, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(from_box), entry_value_from, TRUE, FALSE, 5);

	gtk_box_pack_start(GTK_BOX(to_box), cb_to, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(to_box), entry_value_to, TRUE, FALSE, 5);

	gtk_box_pack_start(GTK_BOX(res_box), bttn_convert, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(res_box), res, TRUE, FALSE, 5);
	
	main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	gtk_box_pack_start(GTK_BOX(main_box), from_box, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(main_box), to_box, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(main_box), res_box, TRUE, FALSE, 5);

	gtk_container_add(GTK_CONTAINER(content_box), main_box);
	gtk_widget_show_all(dialog);
}
