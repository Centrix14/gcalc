#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>

/*
 * gcalc - graphical calculator v0.4
 * by Centrix
 * 24.09.2019
 */

void num_bttn_click(GtkWidget *bttn, gpointer label);
void c_bttn_click(GtkWidget *bttn, gpointer label);
void op_bttn_click(GtkWidget *bttn, gpointer data);
void eq_bttn_click(GtkWidget *bttn, gpointer label);
void tn1_bttn_click(GtkWidget *bttn, gpointer data);
void tn2_bttn_click(GtkWidget *bttn, gpointer data);
void r_bttn_click(GtkWidget *bttn, gpointer label);
void w_bttn_click(GtkWidget *bttn, gpointer label);
void w_bttn_click(GtkWidget *bttn, gpointer label);

int num1 = 0, num2 = 0, op = 0;
int *num_ptr = &num1;

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *bttn_1, *bttn_2, *bttn_3, *bttn_4, *bttn_5, *bttn_6, *bttn_7, *bttn_8, *bttn_9, *bttn_0;
	GtkWidget *bttn_sum, *bttn_subt, *bttn_mult, *bttn_div, *bttn_eq, *bttn_c, *bttn_pow, *bttn_sqrt, *bttn_inv, *bttn_dbm;
	GtkWidget *bttn_tn1, *bttn_tn2, *bttn_r, *bttn_w;
	GtkWidget *answer;
	GtkWidget *num_pad, *row1, *row2, *row3, *row4, *row5, *row6, *mbox;

	gtk_init(&argc, &argv);

	// Создаём окно
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "gcalc");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

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

	// Кнопки операций
	bttn_sum = gtk_button_new_with_label("+");
	bttn_subt = gtk_button_new_with_label("-");
	bttn_mult = gtk_button_new_with_label("x");
	bttn_div = gtk_button_new_with_label("/");
	bttn_eq = gtk_button_new_with_label("=");
	bttn_c = gtk_button_new_with_label("C");
	bttn_pow = gtk_button_new_with_label("^");
	bttn_sqrt = gtk_button_new_with_label("R");
	bttn_inv = gtk_button_new_with_label("I");
	bttn_dbm = gtk_button_new_with_label("%");

	// Специальные кнопки
	bttn_tn1 = gtk_button_new_with_label("TN1");
	bttn_tn2 = gtk_button_new_with_label("TN2");
	bttn_r = gtk_button_new_with_label("BR");
	bttn_w = gtk_button_new_with_label("BW");

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

	// Связываем кнопки +, -, x, / с, ^, R, I, % функцией op_bttn_click
	g_signal_connect(G_OBJECT(bttn_sum), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_subt), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_mult), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_div), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_pow), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_sqrt), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_inv), "clicked", G_CALLBACK(op_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_dbm), "clicked", G_CALLBACK(op_bttn_click), NULL);

	// Связываем кнопку = с функцией eq_bttn_click
	g_signal_connect(G_OBJECT(bttn_eq), "clicked", G_CALLBACK(eq_bttn_click), answer);

	// Связывакм кнопки tn1, tn2, r, w с функциями tn1_bttn_click, tn2_bttn_click, r_bttn_click, w_bttn_click
	g_signal_connect(G_OBJECT(bttn_tn1), "clicked", G_CALLBACK(tn1_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_tn2), "clicked", G_CALLBACK(tn2_bttn_click), NULL);
	g_signal_connect(G_OBJECT(bttn_r), "clicked", G_CALLBACK(r_bttn_click), answer);
	g_signal_connect(G_OBJECT(bttn_w), "clicked", G_CALLBACK(w_bttn_click), answer);

	// Ряды кнопок
	row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	row6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

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
	gtk_box_pack_start(GTK_BOX(row6), bttn_tn1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_tn2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_r, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(row6), bttn_w, TRUE, FALSE, 5);

	// num_pad - панель ввода чисел и операций
	num_pad = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// Добавляем ряды кнопок в num_pad
	gtk_box_pack_start(GTK_BOX(num_pad), row1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row3, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row4, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row5, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(num_pad), row6, TRUE, FALSE, 5);

	// mbox - основной контейнер
	mbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// Добавляем num_pad и answer в mbox
	gtk_box_pack_start(GTK_BOX(mbox), answer, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(mbox), num_pad, TRUE, FALSE, 5);

	// Добавляем основной контейнер к окну
	gtk_container_add(GTK_CONTAINER(window), mbox);
	gtk_widget_show_all(window);

	gtk_main(); 
	return 0;
}

void num_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];

	*num_ptr = *num_ptr * 10 + atoi( gtk_button_get_label(GTK_BUTTON(bttn)) );

	sprintf(tmp, "%d", *num_ptr);
	gtk_label_set_text(GTK_LABEL(label), tmp);
}

void c_bttn_click(GtkWidget *bttn, gpointer label) {
	*num_ptr = 0;
	gtk_label_set_text(GTK_LABEL(label), "0");
}

void op_bttn_click(GtkWidget *bttn, gpointer data) {
	num_ptr = &num2;
	op = gtk_button_get_label(GTK_BUTTON(bttn))[0];
}

void eq_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];

	switch (op) {
		case '+': 
			sprintf(tmp, "%d", num1+num2);
			break;
		case '-': 
			sprintf(tmp, "%d", num1-num2);
			break;
		case 'x': 
			sprintf(tmp, "%d", num1*num2);
			break;
		case '/': 
			if ( num2 != 0 )
				sprintf(tmp, "%d", num1/num2);
			else {
				gtk_label_set_text(GTK_LABEL(label), "The surgery doesn't make sense.");
				return;
			}
			break;
		case '^': 
			sprintf(tmp, "%f", pow(num1, num2));
			break;	
		case 'R':
			sprintf(tmp, "%f", sqrt( atof(gtk_label_get_text(GTK_LABEL(label))) ));
			break;
		case 'I':
			sprintf(tmp, "%d", -atoi( gtk_label_get_text(GTK_LABEL(label)) ));
			break;
		case '%':
			sprintf(tmp, "%d", num1%num2);
			break;
	}
	
	gtk_label_set_text(GTK_LABEL(label), tmp);
}

void tn1_bttn_click(GtkWidget *bttn, gpointer data) {
	num_ptr = &num1;
}

void tn2_bttn_click(GtkWidget *bttn, gpointer data) {
	num_ptr = &num2;
}

void r_bttn_click(GtkWidget *bttn, gpointer label) {
	char tmp[256];
	sprintf(tmp, "%d", *num_ptr);
	gtk_label_set_text(GTK_LABEL(label), tmp);
}

void w_bttn_click(GtkWidget *bttn, gpointer label) {
	*num_ptr = atoi( gtk_label_get_text(GTK_LABEL(label)) );
}
