/*
 * libdivecomputer
 *
 * Copyright (C) 2016 Jef Driesen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef DC_USBHID_H
#define DC_USBHID_H

#include <libdivecomputer/common.h>
#include <libdivecomputer/context.h>
#include <libdivecomputer/iostream.h>
#include <libdivecomputer/iterator.h>
#include <libdivecomputer/descriptor.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Opaque object representing a USB HID device.
 */
typedef struct dc_usbhid_device_t dc_usbhid_device_t;

/**
 * Get the vendor id (VID) of the USB HID device.
 *
 * @param[in]  device  A valid USB HID device.
 */
unsigned int
dc_usbhid_device_get_vid (dc_usbhid_device_t *device);

/**
 * Get the product id (PID) of the USB HID device.
 *
 * @param[in]  device  A valid USB HID device.
 */
unsigned int
dc_usbhid_device_get_pid (dc_usbhid_device_t *device);

/**
 * Destroy the USB HID device and free all resources.
 *
 * @param[in]  device  A valid USB HID device.
 */
void
dc_usbhid_device_free(dc_usbhid_device_t *device);

/**
 * Create an iterator to enumerate the USB HID devices.
 *
 * @param[out] iterator    A location to store the iterator.
 * @param[in]  context     A valid context object.
 * @param[in]  descriptor  A valid device descriptor or NULL.
 * @returns #DC_STATUS_SUCCESS on success, or another #dc_status_t code
 * on failure.
 */
dc_status_t
dc_usbhid_iterator_new (dc_iterator_t **iterator, dc_context_t *context, dc_descriptor_t *descriptor);

/**
 * Open a USB HID connection.
 *
 * @param[out]  iostream A location to store the USB HID connection.
 * @param[in]   context  A valid context object.
 * @param[in]   vid      The USB Vendor ID of the device.
 * @param[in]   pid      The USB Product ID of the device.
 * @returns #DC_STATUS_SUCCESS on success, or another #dc_status_t code
 * on failure.
 */
dc_status_t
dc_usbhid_open (dc_iostream_t **iostream, dc_context_t *context, unsigned int vid, unsigned int pid);

/* Create a dc_custom_io_t that uses usbhid for packet transfer */
dc_status_t
dc_usbhid_custom_io(dc_context_t *context, unsigned int vid, unsigned int pid);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DC_USBHID_H */
