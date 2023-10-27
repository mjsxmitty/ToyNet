
#ifndef __NLP_PLAY_AGAIN_H__
#define __NLP_PLAY_AGAIN_H__

int play_again();

int get_response(int max_tries);

void set_crmode();

char get_ok_char();

void set_nodelay_mode();

void tty_mode(int how);


#endif // __NLP_PLAY_AGAIN_H__
