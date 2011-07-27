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

extern int xmax, ymax;
extern int screen, fd;
extern int histcol;
extern int freq;
extern int parity;
extern int width, wide;
extern int height, high;
extern int quilt;
extern int begin;
extern int col;
extern int draw;
extern int minhist, maxhist;
extern int logistic;			/* use logistic map */
extern int tent;				/* use tent map */
extern int circle;			/* use circle map if set */
extern int Cflag;			/* Show connection strengths */
extern int Eflag;			/* Evolve connection strengths */
extern int sflag;			/* spatial histogram off */
extern int hflag;			/* site histogram off */
extern int oflag;			/* output file off */
extern int vflag;		/* don't display text windows describing dynamics */
extern int ranlam;			/* random lambda values off */
extern int linlam;			/* linearly assigned lambda values off */
extern int perlam;			/* periodically assigned lambda values off */
extern int rancon;			/* random connection values off */
extern int lincon;			/* linearly assigned connection values off */
extern int percon;		/* periodically assigned connection values off */
extern int eflag;			/* erase flag */
extern int Pflag;			/* draw points flag */
extern int mflag; 		/* monochrome display (site value > 1/2 -> color) */
extern int pflag;			/* generate phase 1st differences */
extern int two_dim;		/* two dimensional lattice ? */
extern int iflag;			/* initial conditions specified */
extern int cflag;			/* draw curves */
extern int xflag;			/* coupled map lattice mode */
extern int xavg;			/* number of generations over which to average */
extern int lamvalset;		/* non-linearity parameter specified */
extern double RANGE;	/* range outside of which differences get graphed*/
extern double erate;		/* rate at which connections evolve */
extern double ORANGE;		/* 1-RANGE */
extern double lamval;		/* default lambda value */
extern double EC;			/* default center cell weight */
extern double ER;			/* default right cell weight */
extern double EL;			/* default left cell weight */
extern double EU;			/* default upper cell weight */
extern double ED;			/* default lower cell weight */
extern double omega;		/* frequency in circle map or height in tent map */
extern double incline, decline;	/* slope up and down (if tent) */
extern char *valinit, *laminit;	/* initial values of array and lambdas */
extern double **ctrconn;	/* initial values of center connection strength */
extern double **rgtconn;	/* initial values of right connection strength */
extern double **lftconn;	/* initial values of left connection strength */
extern double **uprconn;	/* initial values of upper connection strength */
extern double **lwrconn;	/* initial values of lower connection strength */
extern int periodic;		/* periodic boundary conditions */
extern int boundflag;		/* alternate boundary conditions specified */
extern int A;				/* frequency of sin wave of initial lambdas */
extern int G;				/* frequency of sin wave of initial connections */
extern double **currentgen, **nextgen;	/* the current and next generation */
extern double **avg;			/* array of averages to be used as parameters */
extern double **lambda;		/* array of non-linearity parameters */
extern double *diff;		/* array of 1st differences */
extern double boundary;		/* default fixed boundary condition */
extern int *histogram;		/* array of site histogram values */
extern int **histarray;		/* array of spatial histogram values */
extern char *outname;
extern unsigned long foreground, background, numgen;
extern int	mincolor, numcolors, displayplanes;
extern int	numwheels;
extern int     rgb_max, stripe_interval;
extern int	savefile;
extern int	run, xpoint, ypoint;
extern double drand48(), sin(), fabs(), floor(), fmod();
extern void srand48();
extern points_t Points;
