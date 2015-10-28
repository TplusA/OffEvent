# Tool that waits for certain keyboard events

## Copyright and contact

OffEvent is released under the terms of the GNU General Public License
version 3 (GPLv3). See file <tt>COPYING</tt> for licensing terms.

Contact:

    T+A elektroakustik GmbH & Co. KG
    Planckstrasse 11
    32052 Herford
    Germany

## Short description

_OffEvent_ reads raw events from a Linux input device and terminates if it sees
a power off or reboot key press. In this case, it prints a corresponding string
that a script can examine to take further actions.
