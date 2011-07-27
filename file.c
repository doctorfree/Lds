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

#include <stdio.h>
#include <stdlib.h>
#include "x.h"
#include "defines.h"
#include "externals.h"
#include "xexterns.h"

void
Cleanup() {
	freemem();
	XCloseDisplay(dpy);
}

/* Store color pics in PPM format and monochrome in PGM */
void
save_to_file(map) 
Pixmap map;
{
	FILE *outfile;
	unsigned char c;
	XImage *ximage;
	static int i,j;
	struct Colormap {
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	};
	struct Colormap *colormap=NULL;

	if (colormap)
		free(colormap);
	if ((colormap=
		(struct Colormap *)malloc(sizeof(struct Colormap)*numcolors))
			== NULL) {
		fprintf(stderr,"Error malloc'ing colormap array\n");
		Cleanup();
		exit(-1);
	}
	outfile = fopen(outname,"w");
	if(!outfile) {
		perror(outname);
		Cleanup();
		exit(-1);
	}

	ximage=XGetImage(dpy, map, 0, 0, width, height, AllPlanes, ZPixmap);

	if (displayplanes > 1) {
		for (i=0;i<numcolors;i++) {
			colormap[i].red=(unsigned char)(Colors[i].red >> 8);
			colormap[i].green=(unsigned char)(Colors[i].green >> 8);
			colormap[i].blue =(unsigned char)(Colors[i].blue >> 8);
		}
		fprintf(outfile,"P%d %d %d\n",6,width,height);
	}
	else
		fprintf(outfile,"P%d %d %d\n",5,width,height);
	fprintf(outfile,"%d\n",numcolors-1);

	for (j=0;j<height;j++)
	    for (i=0;i<width;i++) {
		c = (unsigned char)XGetPixel(ximage,i,j);
		if (displayplanes > 1)
		    fwrite((char *)&colormap[c],sizeof colormap[0],1,outfile);
		else
		    fwrite((char *)&c,sizeof c,1,outfile);
	    }
	fclose(outfile);
}
