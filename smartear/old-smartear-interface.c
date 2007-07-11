/* GPL Header */

#ifdef HAVE_CONFIG_H
#   include "../pp_config.h"
#endif

#include <gtk/gtk.h>

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_config (void)
{
  GtkWidget *config_vbox;
  GtkWidget *frame1;
  GtkWidget *table1;
  GtkWidget *label9;
  GtkObject *delay_spin_adj;
  GtkWidget *delay_spin;
  GtkWidget *focus_but;
  GtkWidget *timer_but;
  GtkWidget *label8;
  GtkWidget *frame2;
  GtkWidget *table2;
  GtkWidget *delete_but;
  GtkWidget *new_but;
  GtkWidget *scrolledwindow2;
  GtkWidget *treeview;
  GtkWidget *edit_but;
  GtkWidget *label7;
  GtkWidget *hbuttonbox1;
  GtkWidget *revert_but;
  GtkWidget *save_but;


  config_vbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_size_request (config_vbox, -1, 640);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (config_vbox), frame1, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame1), 5);

  table1 = gtk_table_new (3, 2, FALSE);
  gtk_widget_show (table1);
  gtk_container_add (GTK_CONTAINER (frame1), table1);
  gtk_container_set_border_width (GTK_CONTAINER (table1), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table1), 10);
  gtk_table_set_col_spacings (GTK_TABLE (table1), 10);

  label9 = gtk_label_new ("Time delay between playing sounds for a particular buddy:");
  gtk_widget_show (label9);
  gtk_table_attach (GTK_TABLE (table1), label9, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label9), 0, 0.5);

  delay_spin_adj = gtk_adjustment_new (60, 0, 1000000, 1, 10, 10);
  delay_spin = gtk_spin_button_new (GTK_ADJUSTMENT (delay_spin_adj), 1, 0);
  gtk_widget_show (delay_spin);
  gtk_table_attach (GTK_TABLE (table1), delay_spin, 1, 2, 0, 1,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_spin_button_set_update_policy (GTK_SPIN_BUTTON (delay_spin), GTK_UPDATE_IF_VALID);

  focus_but = gtk_check_button_new_with_mnemonic ("Don't play sounds for the conversation that has focus.");
  gtk_widget_show (focus_but);
  gtk_table_attach (GTK_TABLE (table1), focus_but, 0, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  timer_but = gtk_check_button_new_with_mnemonic ("Also play sounds if you don't respond to a particular IM within a delay period.");
  gtk_widget_show (timer_but);
  gtk_table_attach (GTK_TABLE (table1), timer_but, 0, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label8 = gtk_label_new ("Options");
  gtk_widget_show (label8);
  gtk_frame_set_label_widget (GTK_FRAME (frame1), label8);

  frame2 = gtk_frame_new (NULL);
  gtk_widget_show (frame2);
  gtk_box_pack_start (GTK_BOX (config_vbox), frame2, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame2), 5);

  table2 = gtk_table_new (2, 3, FALSE);
  gtk_widget_show (table2);
  gtk_container_add (GTK_CONTAINER (frame2), table2);
  gtk_container_set_border_width (GTK_CONTAINER (table2), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table2), 10);
  gtk_table_set_col_spacings (GTK_TABLE (table2), 10);

  delete_but = gtk_button_new_from_stock ("gtk-delete");
  gtk_widget_show (delete_but);
  gtk_table_attach (GTK_TABLE (table2), delete_but, 2, 3, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  GTK_WIDGET_SET_FLAGS (delete_but, GTK_CAN_DEFAULT);

  new_but = gtk_button_new_from_stock ("gtk-new");
  gtk_widget_show (new_but);
  gtk_table_attach (GTK_TABLE (table2), new_but, 0, 1, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  GTK_WIDGET_SET_FLAGS (new_but, GTK_CAN_DEFAULT);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_table_attach (GTK_TABLE (table2), scrolledwindow2, 0, 3, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

  treeview = gtk_tree_view_new ();
  gtk_widget_show (treeview);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), treeview);

  edit_but = gtk_button_new_from_stock ("gtk-properties");
  gtk_widget_show (edit_but);
  gtk_table_attach (GTK_TABLE (table2), edit_but, 1, 2, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  label7 = gtk_label_new ("Entries");
  gtk_widget_show (label7);
  gtk_frame_set_label_widget (GTK_FRAME (frame2), label7);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (config_vbox), hbuttonbox1, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox1), 5);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_SPREAD);

  revert_but = gtk_button_new_from_stock ("gtk-revert-to-saved");
  gtk_widget_show (revert_but);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), revert_but);
  GTK_WIDGET_SET_FLAGS (revert_but, GTK_CAN_DEFAULT);

  save_but = gtk_button_new_from_stock ("gtk-save");
  gtk_widget_show (save_but);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), save_but);
  GTK_WIDGET_SET_FLAGS (save_but, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) config_vbox, "destroy",
                    G_CALLBACK (on_config_destroy),
                    NULL);
  g_signal_connect ((gpointer) delay_spin, "changed",
                    G_CALLBACK (on_delay_changed),
                    NULL);
  g_signal_connect ((gpointer) focus_but, "toggled",
                    G_CALLBACK (on_focus_toggled),
                    NULL);
  g_signal_connect ((gpointer) timer_but, "toggled",
                    G_CALLBACK (on_timer_toggled),
                    NULL);
  g_signal_connect ((gpointer) delete_but, "clicked",
                    G_CALLBACK (on_delete_clicked),
                    NULL);
  g_signal_connect ((gpointer) new_but, "clicked",
                    G_CALLBACK (on_new_clicked),
                    NULL);
  g_signal_connect ((gpointer) edit_but, "clicked",
                    G_CALLBACK (on_edit_clicked),
                    NULL);
  g_signal_connect ((gpointer) revert_but, "clicked",
                    G_CALLBACK (on_revert_clicked),
                    NULL);
  g_signal_connect ((gpointer) save_but, "clicked",
                    G_CALLBACK (on_save_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, config_vbox, "config_vbox");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, frame1, "frame1");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, table1, "table1");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, label9, "label9");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, delay_spin, "delay_spin");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, focus_but, "focus_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, timer_but, "timer_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, label8, "label8");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, frame2, "frame2");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, table2, "table2");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, delete_but, "delete_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, new_but, "new_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, treeview, "treeview");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, edit_but, "edit_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, label7, "label7");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, hbuttonbox1, "hbuttonbox1");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, revert_but, "revert_but");
  GLADE_HOOKUP_OBJECT_NO_REF (config_vbox, save_but, "save_but");

  return config_vbox;
}

GtkWidget*
create_file_browse (void)
{
  GtkWidget *file_browse;
  GtkWidget *ok_button1;
  GtkWidget *cancel_button1;

  file_browse = gtk_file_selection_new ("Select Sound");
  gtk_container_set_border_width (GTK_CONTAINER (file_browse), 10);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (file_browse), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (file_browse), GDK_WINDOW_TYPE_HINT_DIALOG);

  ok_button1 = GTK_FILE_SELECTION (file_browse)->ok_button;
  gtk_widget_show (ok_button1);
  GTK_WIDGET_SET_FLAGS (ok_button1, GTK_CAN_DEFAULT);

  cancel_button1 = GTK_FILE_SELECTION (file_browse)->cancel_button;
  gtk_widget_show (cancel_button1);
  GTK_WIDGET_SET_FLAGS (cancel_button1, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) file_browse, "destroy",
                    G_CALLBACK (on_file_browse_destroy),
                    NULL);
  g_signal_connect ((gpointer) ok_button1, "clicked",
                    G_CALLBACK (on_browse_ok_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) ok_button1, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (file_browse));
  g_signal_connect_swapped ((gpointer) cancel_button1, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (file_browse));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (file_browse, file_browse, "file_browse");
  GLADE_HOOKUP_OBJECT_NO_REF (file_browse, ok_button1, "ok_button1");
  GLADE_HOOKUP_OBJECT_NO_REF (file_browse, cancel_button1, "cancel_button1");

  return file_browse;
}

GtkWidget*
create_edit_win (void)
{
  GtkWidget *edit_win;
  GtkWidget *vbox1;
  GtkWidget *hbox1;
  GtkWidget *label29;
  GtkWidget *name_entry;
  GtkWidget *label30;
  GtkWidget *type_option;
  GtkWidget *menu1;
  GtkWidget *item_buddy;
  GtkWidget *item_group;
  GtkWidget *hbuttonbox2;
  GtkWidget *applysave_but;
  GtkWidget *apply_but;
  GtkWidget *cancel_but;
  GtkWidget *frame3;
  GtkWidget *table5;
  GtkWidget *label31;
  GtkWidget *label34;
  GtkWidget *label33;
  GtkWidget *label32;
  GtkWidget *unaway_sound_entry;
  GtkWidget *unidle_sound_entry;
  GtkWidget *signon_sound_entry;
  GtkWidget *unaway_test_but;
  GtkWidget *unidle_test_but;
  GtkWidget *signon_test_but;
  GtkWidget *unaway_browse_but;
  GtkWidget *unidle_browse_but;
  GtkWidget *signon_browse_but;
  GtkWidget *im_browse_but;
  GtkWidget *im_sound_entry;
  GtkWidget *im_test_but;
  GtkWidget *label24;

  edit_win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (edit_win, 600, 300);
  gtk_window_set_title (GTK_WINDOW (edit_win), "Edit Entry");
  gtk_window_set_default_size (GTK_WINDOW (edit_win), 600, 300);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (edit_win), vbox1);

  hbox1 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, FALSE, TRUE, 10);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1), 5);

  label29 = gtk_label_new ("Name:");
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox1), label29, FALSE, FALSE, 0);
  gtk_misc_set_alignment (GTK_MISC (label29), 1, 0.5);

  name_entry = gtk_entry_new ();
  gtk_widget_show (name_entry);
  gtk_box_pack_start (GTK_BOX (hbox1), name_entry, TRUE, TRUE, 0);

  label30 = gtk_label_new ("Type:");
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox1), label30, FALSE, TRUE, 0);
  gtk_misc_set_alignment (GTK_MISC (label30), 1, 0.5);

  type_option = gtk_option_menu_new ();
  gtk_widget_show (type_option);
  gtk_box_pack_start (GTK_BOX (hbox1), type_option, FALSE, FALSE, 0);

  menu1 = gtk_menu_new ();

  item_buddy = gtk_menu_item_new_with_mnemonic ("Buddy");
  gtk_widget_show (item_buddy);
  gtk_container_add (GTK_CONTAINER (menu1), item_buddy);

  item_group = gtk_menu_item_new_with_mnemonic ("Group");
  gtk_widget_show (item_group);
  gtk_container_add (GTK_CONTAINER (menu1), item_group);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (type_option), menu1);

  hbuttonbox2 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox2);
  gtk_box_pack_end (GTK_BOX (vbox1), hbuttonbox2, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox2), 5);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox2), GTK_BUTTONBOX_SPREAD);

  applysave_but = gtk_button_new_with_mnemonic ("Apply and Save");
  gtk_widget_show (applysave_but);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), applysave_but);
  GTK_WIDGET_SET_FLAGS (applysave_but, GTK_CAN_DEFAULT);

  apply_but = gtk_button_new_from_stock ("gtk-apply");
  gtk_widget_show (apply_but);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), apply_but);
  GTK_WIDGET_SET_FLAGS (apply_but, GTK_CAN_DEFAULT);

  cancel_but = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancel_but);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), cancel_but);
  GTK_WIDGET_SET_FLAGS (cancel_but, GTK_CAN_DEFAULT);

  frame3 = gtk_frame_new (NULL);
  gtk_widget_show (frame3);
  gtk_box_pack_start (GTK_BOX (vbox1), frame3, FALSE, FALSE, 0);
  gtk_widget_set_size_request (frame3, -1, 200);
  gtk_container_set_border_width (GTK_CONTAINER (frame3), 5);

  table5 = gtk_table_new (4, 5, FALSE);
  gtk_widget_show (table5);
  gtk_container_add (GTK_CONTAINER (frame3), table5);
  gtk_widget_set_size_request (table5, 600, 400);
  gtk_container_set_border_width (GTK_CONTAINER (table5), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table5), 10);
  gtk_table_set_col_spacings (GTK_TABLE (table5), 10);

  label31 = gtk_label_new ("Play On IM:");
  gtk_widget_show (label31);
  gtk_table_attach (GTK_TABLE (table5), label31, 0, 1, 0, 1,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label31), 0, 0.5);

  label34 = gtk_label_new ("Play On Unaway:");
  gtk_widget_show (label34);
  gtk_table_attach (GTK_TABLE (table5), label34, 0, 1, 3, 4,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label34), 0, 0.5);

  label33 = gtk_label_new ("Play On Unidle:");
  gtk_widget_show (label33);
  gtk_table_attach (GTK_TABLE (table5), label33, 0, 1, 2, 3,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label33), 0, 0.5);

  label32 = gtk_label_new ("Play On Signon:");
  gtk_widget_show (label32);
  gtk_table_attach (GTK_TABLE (table5), label32, 0, 1, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label32), 0, 0.5);

  unaway_sound_entry = gtk_entry_new ();
  gtk_widget_show (unaway_sound_entry);
  gtk_table_attach (GTK_TABLE (table5), unaway_sound_entry, 1, 3, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  unidle_sound_entry = gtk_entry_new ();
  gtk_widget_show (unidle_sound_entry);
  gtk_table_attach (GTK_TABLE (table5), unidle_sound_entry, 1, 3, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  signon_sound_entry = gtk_entry_new ();
  gtk_widget_show (signon_sound_entry);
  gtk_table_attach (GTK_TABLE (table5), signon_sound_entry, 1, 3, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  unaway_test_but = gtk_button_new_with_mnemonic ("Test");
  gtk_widget_show (unaway_test_but);
  gtk_table_attach (GTK_TABLE (table5), unaway_test_but, 4, 5, 3, 4,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  unidle_test_but = gtk_button_new_with_mnemonic ("Test");
  gtk_widget_show (unidle_test_but);
  gtk_table_attach (GTK_TABLE (table5), unidle_test_but, 4, 5, 2, 3,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  signon_test_but = gtk_button_new_with_mnemonic ("Test");
  gtk_widget_show (signon_test_but);
  gtk_table_attach (GTK_TABLE (table5), signon_test_but, 4, 5, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  unaway_browse_but = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (unaway_browse_but);
  gtk_table_attach (GTK_TABLE (table5), unaway_browse_but, 3, 4, 3, 4,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  unidle_browse_but = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (unidle_browse_but);
  gtk_table_attach (GTK_TABLE (table5), unidle_browse_but, 3, 4, 2, 3,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  signon_browse_but = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (signon_browse_but);
  gtk_table_attach (GTK_TABLE (table5), signon_browse_but, 3, 4, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  im_browse_but = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (im_browse_but);
  gtk_table_attach (GTK_TABLE (table5), im_browse_but, 3, 4, 0, 1,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  im_sound_entry = gtk_entry_new ();
  gtk_widget_show (im_sound_entry);
  gtk_table_attach (GTK_TABLE (table5), im_sound_entry, 1, 3, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  im_test_but = gtk_button_new_with_mnemonic ("Test");
  gtk_widget_show (im_test_but);
  gtk_table_attach (GTK_TABLE (table5), im_test_but, 4, 5, 0, 1,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  label24 = gtk_label_new ("Sound Events");
  gtk_widget_show (label24);
  gtk_frame_set_label_widget (GTK_FRAME (frame3), label24);

  g_signal_connect ((gpointer) edit_win, "destroy",
                    G_CALLBACK (on_edit_win_destroy),
                    NULL);
  g_signal_connect ((gpointer) applysave_but, "clicked",
                    G_CALLBACK (on_apply_clicked),
                    NULL);
  g_signal_connect ((gpointer) applysave_but, "clicked",
                    G_CALLBACK (on_save_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) applysave_but, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (edit_win));
  g_signal_connect ((gpointer) apply_but, "clicked",
                    G_CALLBACK (on_apply_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) apply_but, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (edit_win));
  g_signal_connect_swapped ((gpointer) cancel_but, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (edit_win));
  g_signal_connect ((gpointer) unaway_test_but, "clicked",
                    G_CALLBACK (on_unaway_test_clicked),
                    NULL);
  g_signal_connect ((gpointer) unidle_test_but, "clicked",
                    G_CALLBACK (on_unidle_test_clicked),
                    NULL);
  g_signal_connect ((gpointer) signon_test_but, "clicked",
                    G_CALLBACK (on_signon_test_clicked),
                    NULL);
  g_signal_connect ((gpointer) unaway_browse_but, "clicked",
                    G_CALLBACK (on_unaway_browse_clicked),
                    NULL);
  g_signal_connect ((gpointer) unidle_browse_but, "clicked",
                    G_CALLBACK (on_unidle_browse_clicked),
                    NULL);
  g_signal_connect ((gpointer) signon_browse_but, "clicked",
                    G_CALLBACK (on_signon_browse_clicked),
                    NULL);
  g_signal_connect ((gpointer) im_browse_but, "clicked",
                    G_CALLBACK (on_im_browse_clicked),
                    NULL);
  g_signal_connect ((gpointer) im_test_but, "clicked",
                    G_CALLBACK (on_im_test_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (edit_win, edit_win, "edit_win");
  GLADE_HOOKUP_OBJECT (edit_win, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (edit_win, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (edit_win, label29, "label29");
  GLADE_HOOKUP_OBJECT (edit_win, name_entry, "name_entry");
  GLADE_HOOKUP_OBJECT (edit_win, label30, "label30");
  GLADE_HOOKUP_OBJECT (edit_win, type_option, "type_option");
  GLADE_HOOKUP_OBJECT (edit_win, menu1, "menu1");
  GLADE_HOOKUP_OBJECT (edit_win, item_buddy, "item_buddy");
  GLADE_HOOKUP_OBJECT (edit_win, item_group, "item_group");
  GLADE_HOOKUP_OBJECT (edit_win, hbuttonbox2, "hbuttonbox2");
  GLADE_HOOKUP_OBJECT (edit_win, applysave_but, "applysave_but");
  GLADE_HOOKUP_OBJECT (edit_win, apply_but, "apply_but");
  GLADE_HOOKUP_OBJECT (edit_win, cancel_but, "cancel_but");
  GLADE_HOOKUP_OBJECT (edit_win, frame3, "frame3");
  GLADE_HOOKUP_OBJECT (edit_win, table5, "table5");
  GLADE_HOOKUP_OBJECT (edit_win, label31, "label31");
  GLADE_HOOKUP_OBJECT (edit_win, label34, "label34");
  GLADE_HOOKUP_OBJECT (edit_win, label33, "label33");
  GLADE_HOOKUP_OBJECT (edit_win, label32, "label32");
  GLADE_HOOKUP_OBJECT (edit_win, unaway_sound_entry, "unaway_sound_entry");
  GLADE_HOOKUP_OBJECT (edit_win, unidle_sound_entry, "unidle_sound_entry");
  GLADE_HOOKUP_OBJECT (edit_win, signon_sound_entry, "signon_sound_entry");
  GLADE_HOOKUP_OBJECT (edit_win, unaway_test_but, "unaway_test_but");
  GLADE_HOOKUP_OBJECT (edit_win, unidle_test_but, "unidle_test_but");
  GLADE_HOOKUP_OBJECT (edit_win, signon_test_but, "signon_test_but");
  GLADE_HOOKUP_OBJECT (edit_win, unaway_browse_but, "unaway_browse_but");
  GLADE_HOOKUP_OBJECT (edit_win, unidle_browse_but, "unidle_browse_but");
  GLADE_HOOKUP_OBJECT (edit_win, signon_browse_but, "signon_browse_but");
  GLADE_HOOKUP_OBJECT (edit_win, im_browse_but, "im_browse_but");
  GLADE_HOOKUP_OBJECT (edit_win, im_sound_entry, "im_sound_entry");
  GLADE_HOOKUP_OBJECT (edit_win, im_test_but, "im_test_but");
  GLADE_HOOKUP_OBJECT (edit_win, label24, "label24");

  return edit_win;
}

