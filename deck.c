#include "deck.h"

/*******************************************************************************
 * Used to create an empty deck ready for processing
 * inputs:
 * - none
 * outputs:
 * - deck_t
*******************************************************************************/
deck_t create_deck(){
    deck_t temp; 
    temp = (deck_t)malloc(sizeof(struct deck));
    strcpy(temp->name, "");
    strcpy(temp->author, "");
    strcpy(temp->owner, "");
    temp->is_public = 0;
    temp->played = 0;
    temp->accuracy = 0;
    temp->cards = NULL;
    temp->next = NULL;
    return temp;
}

/*******************************************************************************
 * Used to add a deck to the deck heap (deck is defined here)
 * inputs:
 * - deck_t (Top of deck heap), string (name for deck), 
 *   string (author), string (owner), int, int, double,
 *   card_t (top of card heap)
 * outputs:
 * - deck_t (Top of deck heap)
*******************************************************************************/
deck_t add_deck(deck_t head, 
        const char name[], 
        const char author[], 
        const char owner[],
        int is_public, 
        int played, 
        double accuracy, 
        card_t cards){
    deck_t temp,p;
    temp = create_deck();
    strcpy(temp->name,name);
    strcpy(temp->author,author);
    strcpy(temp->owner,owner);
    temp->is_public = is_public;
    temp->played = played;
    temp->accuracy = accuracy;
    temp->cards = cards;
    /*checks to see if deck is empty*/
    if(!strcmp(head->name, "")){
        head = temp; 
    }else{ /*else append to end ofdeck*/
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

/*******************************************************************************
 * get name from the deck 'deck' and write it to the given array
 * inputs:
 * - deck_t, string (name)
 * outputs:
 * - none
*******************************************************************************/
void get_name(deck_t deck, char name[]){
    strcpy(name, deck->name);
}

/*******************************************************************************
 * get name in position 'pos' from the
 * sequence of decks from the top of the stack 'deck'
 * inputs:
 * - deck_t, int, string (name)
 * outputs:
 * - none
*******************************************************************************/
void get_name_at(deck_t deck, int pos, char name[]){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            strcpy(name, temp->name);
            return;
        }
        temp = temp->next;
    }
    strcpy(name, "invalid index");
}

/*******************************************************************************
 * get cards from the deck 'deck' and return the top of the card heap
 * inputs:
 * - deck_t
 * outputs:
 * - card_t
*******************************************************************************/
card_t get_cards(deck_t deck){
    return deck->cards;
}

/*******************************************************************************
 * get cards in position 'pos' from the
 * sequence of decks from the top of the stack 'deck'
 * inputs:
 * - deck_t, pos
 * outputs:
 * - card_t (top of heap)
*******************************************************************************/
card_t get_cards_at(deck_t deck, int pos){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            return temp->cards;
        }
        temp = temp->next;
    }
    return NULL;
}

/*******************************************************************************
 * set the name and cards parameter of a given deck 'deck'
 * inputs:
 * - deck_t, string (name), card_t (top of card heap)
 * outputs:
 * - none
*******************************************************************************/
void set_deck(deck_t deck, const char name[], card_t cards){
    strcpy(deck->name, name);
    deck->cards = cards;
}

/*******************************************************************************
 * set name and cards in position 'pos' from the
 * sequence of decks from the top of the stack 'deck'
 * inputs:
 * - deck_t, int, string (name), card_t (top of stack)
 * outputs:
 * - none
*******************************************************************************/
void set_deck_at(deck_t deck, int pos, const char name[], card_t cards){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            strcpy(temp->name, name);
            temp->cards = cards;
            return;
        }
        temp = temp->next;
    }
}

/*******************************************************************************
 * get times played from the deck 'deck'
 * inputs:
 * - deck_t
 * outputs:
 * - int
*******************************************************************************/
int get_played(deck_t deck){
    return deck->played;
}

/*******************************************************************************
 * get times played in position 'pos' from the
 * sequence of decks starting at the top of the stack 'deck'
 * inputs:
 * - deck_t, int
 * outputs:
 * - int
*******************************************************************************/
int get_times_played_at(deck_t deck, int pos){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            return temp->played;
        }
        temp = temp->next;
    }
    return -1;
}

/*******************************************************************************
 * get accuracy from the deck 'deck'
 * inputs:
 * - deck_t
 * outputs:
 * - double
*******************************************************************************/
double get_accuracy(deck_t deck){
    return deck->accuracy;
}

/*******************************************************************************
 * get accuracy in position 'pos' from the
 * sequence of decks starting at the top of the stack 'deck'
 * inputs:
 * - deck_t, int
 * outputs:
 * - double
*******************************************************************************/
double get_accuracy_at(deck_t deck, int pos){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            return temp->accuracy;
        }
        temp = temp->next;
    }
    return -1;
}

/*******************************************************************************
 * get author from the deck 'deck'
 * inputs:
 * - deck_t
 * outputs:
 * - none
*******************************************************************************/
void get_author(deck_t deck, char author[]){
    strcpy(author, deck->author);
}

/*******************************************************************************
 * get author in position 'pos' from the
 * sequence of decks starting at the top of the stack 'deck'
 * inputs:
 * - deck_t, int, string (author)
 * outputs:
 * - none
*******************************************************************************/
void get_author_at(deck_t deck, int pos, char author[]){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            strcpy(author, temp->author);
            return;
        }
        temp = temp->next;
    }
    strcpy(author, "invalid index");
}

/*******************************************************************************
 * get owner from the deck 'deck'
 * inputs:
 * - deck_t
 * outputs:
 * - none
*******************************************************************************/
void get_owner(deck_t deck, char owner[]){
    strcpy(owner, deck->owner);
}

/*******************************************************************************
 * get owner in position 'pos' from the
 * sequence of decks starting at the top of the stack 'deck'
 * inputs:
 * - deck_t, int, string (owner)
 * outputs:
 * - none
*******************************************************************************/
void get_owner_at(deck_t deck, int pos, char owner[]){
    deck_t temp;
    temp = deck;
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i == pos){
            strcpy(owner, temp->owner);
            return;
        }
        temp = temp->next;
    }
    strcpy(owner, "invalid index");
}

/*******************************************************************************
 * Updates the accuracy of a deck after a new game has been played
 * inputs:
 * - deck_t, int
 * outputs:
 * - none
*******************************************************************************/
void update_stats(deck_t deck, int correct){
    /*Updates stats using following formula:
     * (Old accuracy * Old Played) + (Correct answers / Total Cards)
     * -------------------------------------------------------------
     *                       (New Played)
     */
    deck->accuracy = ((deck->accuracy * (double) deck->played) + 
        ((double) correct / (double) get_size(deck->cards))) / 
        (double ) (deck->played + 1);
    deck->played++;
}

/*******************************************************************************
 * get how many decks there are in a heap
 * inputs:
 * - deck_t (top of heap)
 * outputs:
 * - int (amount of decks)
*******************************************************************************/
int get_deck_size(deck_t deck){
    if(deck->next == NULL){
        return 1;
    }
    return get_deck_size(deck->next) + 1;
}

/*******************************************************************************
 * get next deck in the linked deck list
 * inputs:
 * - deck_t
 * outputs:
 * - deck_t (next deck)
*******************************************************************************/
deck_t get_next_deck(deck_t deck){
    return deck->next;
}

/*******************************************************************************
 * Adds a deck to the end of the deck DB
 * inputs:
 * - deck_t
 * outputs:
 * - None
*******************************************************************************/
void update_deck_db(deck_t deck){
    deck_t current_deck = deck;
    card_t current_card = deck->cards;
    FILE * filep;
    filep = fopen(DB_DECKS, "a");
    fprintf(filep, "%s %s\n", "name", current_deck->name);
    fprintf(filep, "%s %s\n", "author", current_deck->author);
    fprintf(filep, "%s %s\n", "owner", current_deck->owner);
    fprintf(filep, "%s %d\n", "is_public", current_deck->is_public);
    fprintf(filep, "%s %d\n", "played", current_deck->played);
    fprintf(filep, "%s %lf\n", "accuracy", current_deck->accuracy);
    int i;
    for(i = 0; i < get_size(current_deck->cards); i++){
        fprintf(filep, "%s %s\n", "question", current_card->question);
        fprintf(filep, "%s %s\n", "answer", current_card->answer);
        current_card = current_card->next;
    }
    fprintf(filep, "%s %s\n", "end", "deck");
    fclose(filep);
}


/*******************************************************************************
 * Edits a decks variables in db
 * inputs:
 * - deck_t, string (name), user_t
 * outputs:
 * - None
*******************************************************************************/
void edit_deck_db(deck_t deck, const char name[], user_t user){
    deck_t current_deck = deck;
    card_t current_card = deck->cards;
    FILE * filep;
    FILE * tempp;
    filep = fopen(DB_DECKS, "r");
    tempp = fopen(DB_TEMP, "w");
    int eof = 1;
    while(eof){
        char temp_l[100] = {'\0'};
        char temp_r[100] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        /*Check to see if deckname is same for edit*/
        if(!strcmp(temp_l, "name") && !strcmp(temp_r, name)){
            fprintf(tempp, "%s %s\n", "name", current_deck->name);
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            /*if deck name is same author will always be the same*/
            fprintf(tempp, "%s %s\n", "author", current_deck->author);
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            /*if username is the same this is correct deck to edit*/
            if(!strcmp(temp_l, "owner") && !strcmp(temp_r, user.username)){
                fprintf(tempp, "%s %s\n", "owner", current_deck->owner);
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                fprintf(tempp, "%s %d\n", "is_public", current_deck->is_public);
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                fprintf(tempp, "%s %d\n", "played", current_deck->played);
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                fprintf(tempp, "%s %lf\n", "accuracy", current_deck->accuracy);
                int i;
                for(i = 0; i < get_size(current_deck->cards); i++){
                    eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                    fprintf(tempp, "%s %s\n", "question", 
                        current_card->question);
                    eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                    fprintf(tempp, "%s %s\n", "answer", current_card->answer);
                    current_card = current_card->next;
                }
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                fprintf(tempp, "%s %s\n", "end", "deck");
            }else{
                fprintf(tempp, "%s %s\n", temp_l, temp_r);
            }
        }else{
            fprintf(tempp, "%s %s\n", temp_l, temp_r);
        }
    }
    fclose(tempp);
    fclose(filep);
    /*Swap decks*/
    remove(DB_DECKS);
    rename(DB_TEMP, DB_DECKS);
}

/*******************************************************************************
 * Deletes a deck from the db by copying deck into a new deck
 * inputs:
 * - deck_t, string (name), user_t
 * outputs:
 * - None
*******************************************************************************/
void delete_deck_db(deck_t deck, const char name[], user_t user){
    deck_t current_deck = deck;
    card_t current_card = deck->cards;
    FILE * filep;
    FILE * tempp;
    filep = fopen(DB_DECKS, "r");
    tempp = fopen(DB_TEMP, "w");
    int eof = 1;
    while(eof){
        char temp_l[100] = {'\0'};
        char temp_r[100] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        /*checks if this is correct deck*/
        if(!strcmp(temp_l, "name") && !strcmp(temp_r, name)){
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            /*double checking user is correct*/
            if(!strcmp(temp_l, "owner") && !strcmp(temp_r, user.username)){
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                int i;
                for(i = 0; i < get_size(current_deck->cards); i++){
                    eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                    eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                    current_card = current_card->next;
                }
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            }else{ /*otherwise copy over contents*/
                fprintf(tempp, "%s %s\n", "name", current_deck->name);
                fprintf(tempp, "%s %s\n", "author", current_deck->author);
                fprintf(tempp, "%s %s\n", temp_l, temp_r);
            }
        }else{
            fprintf(tempp, "%s %s\n", temp_l, temp_r);
        }
    }
    fclose(tempp);
    fclose(filep);
    remove(DB_DECKS);
    rename(DB_TEMP, DB_DECKS);
}

/*******************************************************************************
 * Gets the last deck of a deck list
 * inputs:
 * - deck_t (top of heap)
 * outputs:
 * - deck_t (last deck)
*******************************************************************************/
deck_t get_last_deck(deck_t deck){
    deck_t temp = deck;
    while(1){
        if(temp->next == NULL){
            return temp;
        }
        temp = temp->next;
    }
}

/*******************************************************************************
 * Loads community decks from the community decks database then returns
 * the top of the deck heap
 * inputs:
 * - None
 * outputs:
 * - deck_t
*******************************************************************************/
deck_t load_community_decks(){
    deck_t final_deck = create_deck();
    deck_t temp_deck = create_deck();
    card_t final_card = create_card();
    card_t temp_card = create_card();
    FILE * filep;
    filep = fopen(DB_COMMUNITY_DECKS, "r");
    if(filep == NULL){
        printf("Could not find Community Deck DB\n");
        return NULL;
    }
    int eof = 1;
    int reading_cards = 0;
    while(eof){
        char temp_l[MAX_INPUT_LENGTH] = {'\0'};
        char temp_r[MAX_INPUT_LENGTH] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!reading_cards){
            if(!strcmp(temp_l, "name")){
                strcpy(temp_deck->name,temp_r);
            }else if(!strcmp(temp_l, "author")){
                strcpy(temp_deck->author,temp_r);
                reading_cards = 1;
            }
        }else{
            if(!strcmp(temp_l, "end")){
                reading_cards = 0;
                final_deck = add_deck(final_deck, 
                    temp_deck->name, 
                    temp_deck->author,
                    "", 1, 
                    temp_deck->played, 
                    temp_deck->accuracy, 
                    final_card);
                temp_card = create_card();
                final_card = create_card();
                temp_deck = create_deck();
            }else if(!strcmp(temp_l, "question")){
                strcpy(temp_card->question,temp_r);
            }else if(!strcmp(temp_l, "answer")){
                strcpy(temp_card->answer,temp_r);
                final_card = add_card(final_card, 
                    temp_card->question, 
                    temp_card->answer);
                temp_card = create_card();
            }
        }
    }
    fclose(filep);
    return final_deck;
}

/*******************************************************************************
 * Load in all the decks of a provided user
 * inputs:
 * - user_t
 * outputs:
 * - deck_t
*******************************************************************************/
deck_t load_user_decks(user_t user){
    deck_t final_deck = create_deck();
    deck_t temp_deck = create_deck();
    card_t final_card = create_card();
    card_t temp_card = create_card();
    FILE * filep;
    filep = fopen(DB_DECKS, "r");
    if(filep == NULL){
        printf("Could not find Deck DB\n");
        return NULL;
    }
    int eof = 1;
    int reading_cards = 0;
    int reading_deck = 0;
    while(eof){
        char temp_l[MAX_INPUT_LENGTH] = {'\0'};
        char temp_r[MAX_INPUT_LENGTH] = {'\0'};
        char *end;
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!reading_cards){
            if(!strcmp(temp_l, "name")){
                strcpy(temp_deck->name,temp_r);
            }else if(!strcmp(temp_l, "author")){
                strcpy(temp_deck->author,temp_r);
            }else if(!strcmp(temp_l, "owner") &&
             !strcmp(temp_r, user.username)){
                strcpy(temp_deck->owner,temp_r);
                reading_deck = 1;
            }else if(!strcmp(temp_l, "is_public")){
                temp_deck->is_public = strtol(temp_r, &end, 10);
            }else if(!strcmp(temp_l, "played")){
                temp_deck->played = strtol(temp_r, &end, 10);
            }else if(!strcmp(temp_l, "accuracy")){
                temp_deck->accuracy = strtod(temp_r, &end);
                if(reading_deck){
                    reading_cards = 1;
                }
            }
        }else{
            if(!strcmp(temp_l, "end")){
                reading_cards = 0;
                reading_deck = 0;
                final_deck = add_deck(final_deck, 
                    temp_deck->name, 
                    temp_deck->author,
                    temp_deck->owner,
                    temp_deck->is_public, 
                    temp_deck->played, 
                    temp_deck->accuracy, 
                    final_card);
                temp_card = create_card();
                final_card = create_card();
                temp_deck = create_deck();
            }else if(!strcmp(temp_l, "question")){
                strcpy(temp_card->question,temp_r);
            }else if(!strcmp(temp_l, "answer")){
                strcpy(temp_card->answer,temp_r);
                final_card = add_card(final_card, 
                    temp_card->question, 
                    temp_card->answer);
                temp_card = create_card();
            }
        }
    }
    fclose(filep);
    return final_deck;
}

/*******************************************************************************
 * Saves the in memory community deck to the community deck database
 * inputs:
 * - deck_t
 * outputs:
 * - None
*******************************************************************************/
void save_community_decks(deck_t deck){
    deck_t current_deck = deck;
    card_t current_card = deck->cards;
    FILE * filep;
    filep = fopen(DB_COMMUNITY_DECKS, "w");
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i > 0){
            current_deck = current_deck->next;
            current_card = current_deck->cards;
        }
        fprintf(filep, "%s %s\n", "name", current_deck->name);
        fprintf(filep, "%s %s\n", "author", current_deck->author);
        int j;
        for(j = 0; j < get_size(current_deck->cards); j++){
            fprintf(filep, "%s %s\n", "question", current_card->question);
            fprintf(filep, "%s %s\n", "answer", current_card->answer);
            current_card = current_card->next;
        }
        fprintf(filep, "%s %s\n", "end", "deck");
    }
    fclose(filep);
}

/*******************************************************************************
 * Checks to see if the deck name exists across all users
 * inputs:
 * - string (deck name)
 * outputs:
 * - int
*******************************************************************************/
int check_deck_exists(const char name[]){
    FILE * filep;
    filep = fopen(DB_COMMUNITY_DECKS, "r");
    if(filep == NULL){
        printf("Could not find Community Deck DB\n");
        return 1;
    }
    int eof = 1;
    while(eof){
        char temp_l[MAX_INPUT_LENGTH] = {'\0'};
        char temp_r[MAX_INPUT_LENGTH] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!strcmp(temp_l, "name") && !strcmp(temp_r, name)){
            fclose(filep);
            return 1;
        }
    }
    fclose(filep);
    return 0;
}