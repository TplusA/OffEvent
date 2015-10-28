/*
 * Copyright (C) 2015  T+A elektroakustik GmbH & Co. KG
 *
 * This file is part of OffEvent.
 *
 * OffEvent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3 as
 * published by the Free Software Foundation.
 *
 * OffEvent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OffEvent.  If not, see <http://www.gnu.org/licenses/>.
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static int open_evdev(const char *device_name)
{
    int fd;

    while((fd = open(device_name, O_RDONLY)) == -1 && errno == EINTR)
        ;

    if(fd < 0)
        perror("open()");

    return fd;
}

static int wait_for_power_key(int fd)
{
    while(1)
    {
        struct input_event evs[8];

        const ssize_t bytes = read(fd, evs, sizeof(evs));

        if(bytes < (ssize_t)sizeof(evs[0]))
        {
            if(errno == EINTR)
                continue;

            perror("read()");
            return -1;
        }

        const size_t count = bytes / sizeof(evs[0]);

        for(size_t i = 0; i < count; ++i)
        {
            const struct input_event *const ev = &evs[i];

            if(ev->type == EV_KEY && ev->value > 0)
            {
                if(ev->code == KEY_POWER)
                    printf("power\n");
                else if(ev->code == KEY_RESTART)
                    printf("reboot\n");
                else
                    continue;

                return 0;
            }
        }
    }
}

static int process_command_line(int argc, char *argv[],
                                const char **device_name)
{
    *device_name = NULL;

#define CHECK_ARGUMENT() \
    do \
    { \
        if(i + 1 >= argc) \
        { \
            fprintf(stderr, "Option %s requires an argument.\n", argv[i]); \
            return -1; \
        } \
        ++i; \
    } \
    while(0)

    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "--help") == 0)
            return 1;
        else if(strcmp(argv[i], "--evdev") == 0)
        {
            CHECK_ARGUMENT();
            *device_name = argv[i];
        }
        else
        {
            fprintf(stderr, "Unknown option \"%s\". Please try --help.\n", argv[i]);
            return -1;
        }
    }

#undef CHECK_ARGUMENT

    if(*device_name == NULL)
    {
        fprintf(stderr, "Missing options. Please try --help.\n");
        return -1;
    }

    return 0;
}

static void usage(const char *program_name)
{
    printf("Usage: %s [options]\n"
           "\n"
           "Options:\n"
           "  --help        Show this help.\n"
           "  --evdev path  Path to event interface (mandatory).\n"
           "\n"
           "This program is part of " PACKAGE_STRING ".\n",
           program_name);
}

int main(int argc, char *argv[])
{
    const char *device_name;
    int ret = process_command_line(argc, argv, &device_name);

    if(ret == -1)
        return EXIT_FAILURE;
    else if(ret == 1)
    {
        usage(argv[0]);
        return EXIT_SUCCESS;
    }

    const int fd = open_evdev(device_name);

    if(fd < 0)
        return EXIT_FAILURE;

    if(wait_for_power_key(fd) < 0)
        return EXIT_FAILURE;

    close(fd);

    return EXIT_SUCCESS;
}
