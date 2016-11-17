//////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006 Audiokinetic Inc. / All Rights Reserved
//
//////////////////////////////////////////////////////////////////////

// MixerStubFXFactory.h

/// \file
/// Plug-in unique ID and creation functions (hooks) necessary to register the mixer plug-in in the sound engine.
/// <br><b>Wwise effect name:</b>  Mixer Stub
/// <br><b>Library file:</b> MixerStub.lib

#ifndef _MIXERSTUBFXFACTORY_H_
#define _MIXERSTUBFXFACTORY_H_


#if !defined AK_3DS && !defined AK_VITA_HW
AK_STATIC_LINK_PLUGIN(MixerStubFX)
AK_STATIC_LINK_PLUGIN(MixerStubFXAttachment)
#endif

#endif // _MIXERSTUBFXFACTORY_H_

