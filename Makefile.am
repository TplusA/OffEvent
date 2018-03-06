#
# Copyright (C) 2015, 2018  T+A elektroakustik GmbH & Co. KG
#
# This file is part of OffEvent.
#
# OffEvent is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 3 as
# published by the Free Software Foundation.
#
# OffEvent is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with OffEvent.  If not, see <http://www.gnu.org/licenses/>.
#

bin_PROGRAMS = offevent

offevent_SOURCES = offevent.c

AM_CFLAGS = $(CWARNINGS)

if WITH_MARKDOWN
html_DATA = README.html
endif

EXTRA_DIST = README.md

CLEANFILES = README.html

.md.html:
	$(MARKDOWN) $< >$@
