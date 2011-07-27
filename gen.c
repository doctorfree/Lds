/*************************************************************************
 *                                                                       *
 * Copyright (c) 1992, 1993 Ronald Joe Record                           *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

#include "defines.h"
#include "externals.h"
#include "xexterns.h"

static row = 0;

/* routines in this file */
void next_gen(), iterate();

/* external routines called in this file */
extern int upd_lambda();
extern void phasediff(), grafline(), grafgen(), adjconn(), FlushPixmap();
extern double map();

/*
 * next_gen() - generate the next generation and graf it.
 */
void
next_gen()
{
	double **tmp;
	static int i, x, y;

	iterate(currentgen, nextgen);
	if (++row >= high) {
		x = xpoint; y = ypoint;
		row = draw = 0;
		if (++numgen > begin)
			draw = 1;
		parity = numgen % freq;
		if (xflag)
			upd_lambda();
		for (i=0; i<high; i++) {
			if (pflag)
				phasediff(nextgen[i]);
			else if (cflag)
				grafline(nextgen[i]);
			else
				grafgen(nextgen[i]);
		}
		if (!cflag) {
			FlushPixmap(dpy, pixmap, Data_GC, &Points, mincolor, numcolors);
			y = height - y - high;
			XCopyArea(dpy, pixmap, canvas, Data_GC[0], x, y, wide, high, x, y);
		}
		tmp = currentgen;
		currentgen = nextgen;
		nextgen = tmp;
		if (Eflag)
			adjconn();
	}
}

/*
 *  generate the next generation.
 *  now - current generation.
 *  new - the next generation.
 */

void
iterate(now, new)
double **new, **now;
{
	static int i, j, k, l, m, n;

	if (row == 0)
		n = high - 1;
	else
		n = row - 1;
	if (row == high - 1)
		m = 0;
	else
		m = row + 1;
	for (j=0; j<wide; j++) {
	  	if (j == 0)
			k = wide -1;
	  	else
			k = j - 1;
	  	if (j == wide - 1)
			l = 0;
	  	else
			l = j + 1;
		new[row][j] = lftconn[row][j]*map(lambda[row][k],now[row][k])
					+ ctrconn[row][j]*map(lambda[row][j],now[row][j])
					+ rgtconn[row][j]*map(lambda[row][l],now[row][l])
					+ uprconn[row][j]*map(lambda[m][j],now[m][j])
					+ lwrconn[row][j]*map(lambda[n][j],now[n][j]);
	}
}
