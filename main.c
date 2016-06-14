#include <gtk/gtk.h>
#include <stdio.h>
#include <glib/gprintf.h>
#include <stdlib.h>


typedef struct{
	GtkWidget *window_main;
	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *entry3;
	GtkWidget *entry4;
	GtkWidget *entry5;
	GtkWidget *entry6;
	GtkWidget *entry7;
	GtkWidget *entry8;
	GtkWidget *entry9;
	GtkWidget *label12;
	GtkWidget *label13;
} AppWidgets;


void help_about(GtkWidget *widget){
	gtk_dialog_run(GTK_DIALOG(widget));
	gtk_widget_hide(widget);

}

int main(int argc, char **argv){

	GtkBuilder *builder;
	AppWidgets *app = g_slice_new(AppWidgets);
	GError *err = NULL;

	gtk_init(&argc, &argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder, "window_main.xml", &err);

	if(err){

		g_error(err->message);
		g_error_free(err);
		g_slice_free(AppWidgets, app);
		return 1;
	}

	#define appGET(xx) \
	app->xx=GTK_WIDGET(gtk_builder_get_object(builder,#xx))
	appGET(entry1);
	appGET(entry2);
	appGET(entry3);
	appGET(entry4);
	appGET(entry5);
	appGET(entry6);
	appGET(entry7);
	appGET(entry8);
	appGET(entry9);
	appGET(label12);
	appGET(label13);
	appGET(window_main);
	gtk_builder_connect_signals(builder, app);
	g_object_unref(G_OBJECT(builder));
	gtk_widget_show(GTK_WIDGET(app->window_main));
	gtk_main();
	g_slice_free(AppWidgets, app);
	return 0;

}
