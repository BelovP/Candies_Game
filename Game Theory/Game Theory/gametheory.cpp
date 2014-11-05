#include "gametheory.h"

GameTheory::GameTheory(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	connect( ui.heap_button_1, SIGNAL(clicked()), this, SLOT(HeapButtonClicked()) );
	connect( ui.heap_button_2, SIGNAL(clicked()), this, SLOT(HeapButtonClicked()) );
	connect( ui.heap_button_3, SIGNAL(clicked()), this, SLOT(HeapButtonClicked()) );

	connect( ui.ok_button_1, SIGNAL(clicked()), this, SLOT(OkButtonClicked()) );
	connect( ui.ok_button_2, SIGNAL(clicked()), this, SLOT(OkButtonClicked()) );
	connect( ui.ok_button_3, SIGNAL(clicked()), this, SLOT(OkButtonClicked()) );

	TurnOffOkButtons();
	TurnOffHeapButtons();

	connect (ui.ok_candies, SIGNAL(clicked()), this, SLOT(CandiesChosen()));

	start_timer = new QTimer(this);
	timer_to_watch_AI = new QTimer(this);
	connect(timer_to_watch_AI, SIGNAL(timeout()), this, SLOT(SwitchTurnToPlayer()));
	connect(start_timer, SIGNAL(timeout()), this, SLOT(StartGame()));

	current_active_player = 1;
	is_start_of_the_game = true;
	ai_player = 2;
	number_of_candies = 100;
	available_candies = number_of_candies;
	number_of_unselected_heaps = 3;
	game_finished = false;
	candies_in_heap.resize(3, 0);
	ui.informer->setText(QString("Choose a player and the number of candies"));
}

GameTheory::~GameTheory()
{

}
