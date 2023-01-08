#/*********************************************************
#
# Copyright (c) 2022 Stephen Rhodes
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#***********************************************************/

cmake_minimum_required(VERSION 3.17)
project(liblivemedia VERSION 2022.12.01)
find_package(OpenSSL REQUIRED)
set(CMAKE_CXX_FLAGS "-DSOCKLEN_T=socklen_t")
include(GNUInstallDirs)
set(CMAKE_INSTALL_INCLUDEDIR "include/${CMAKE_LIBRARY_ARCHITECTURE}")

if(WIN32)
    add_compile_options("/EHsc")
    add_compile_definitions("NO_GETIFADDRS")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

add_library(livemedia SHARED

    UsageEnvironment/HashTable.cpp
    UsageEnvironment/UsageEnvironment.cpp
    UsageEnvironment/strDup.cpp

    BasicUsageEnvironment/BasicHashTable.cpp
    BasicUsageEnvironment/BasicTaskScheduler.cpp
    BasicUsageEnvironment/BasicUsageEnvironment.cpp
    BasicUsageEnvironment/BasicTaskScheduler0.cpp
    BasicUsageEnvironment/BasicUsageEnvironment0.cpp
    BasicUsageEnvironment/DelayQueue.cpp

    groupsock/GroupEId.cpp
    groupsock/GroupsockHelper.cpp
    groupsock/NetAddress.cpp
    groupsock/Groupsock.cpp
    groupsock/IOHandlers.cpp
    groupsock/NetInterface.cpp
    groupsock/inet.c

    liveMedia/AC3AudioFileServerMediaSubsession.cpp
    liveMedia/AC3AudioRTPSink.cpp
    liveMedia/AC3AudioRTPSource.cpp
    liveMedia/AC3AudioStreamFramer.cpp
    liveMedia/ADTSAudioFileServerMediaSubsession.cpp
    liveMedia/ADTSAudioFileSource.cpp
    liveMedia/ADTSAudioStreamDiscreteFramer.cpp
    liveMedia/AMRAudioFileServerMediaSubsession.cpp
    liveMedia/AMRAudioFileSink.cpp
    liveMedia/AMRAudioFileSource.cpp
    liveMedia/AMRAudioRTPSink.cpp
    liveMedia/AMRAudioRTPSource.cpp
    liveMedia/AMRAudioSource.cpp
    liveMedia/AudioInputDevice.cpp
    liveMedia/AudioRTPSink.cpp
    liveMedia/AVIFileSink.cpp
    liveMedia/Base64.cpp
    liveMedia/BasicUDPSink.cpp
    liveMedia/BasicUDPSource.cpp
    liveMedia/BitVector.cpp
    liveMedia/ByteStreamFileSource.cpp
    liveMedia/ByteStreamMemoryBufferSource.cpp
    liveMedia/ByteStreamMultiFileSource.cpp
    liveMedia/DeviceSource.cpp
    liveMedia/DigestAuthentication.cpp
    liveMedia/DVVideoFileServerMediaSubsession.cpp
    liveMedia/DVVideoRTPSink.cpp
    liveMedia/DVVideoRTPSource.cpp
    liveMedia/DVVideoStreamFramer.cpp
    liveMedia/EBMLNumber.cpp
    liveMedia/FileServerMediaSubsession.cpp
    liveMedia/FileSink.cpp
    liveMedia/FramedFileSource.cpp
    liveMedia/FramedFilter.cpp
    liveMedia/FramedSource.cpp
    liveMedia/GenericMediaServer.cpp
    liveMedia/GSMAudioRTPSink.cpp
    liveMedia/H261VideoRTPSource.cpp
    liveMedia/H263plusVideoFileServerMediaSubsession.cpp
    liveMedia/H263plusVideoRTPSink.cpp
    liveMedia/H263plusVideoRTPSource.cpp
    liveMedia/H263plusVideoStreamFramer.cpp
    liveMedia/H263plusVideoStreamParser.cpp
    liveMedia/H264or5VideoFileSink.cpp
    liveMedia/H264or5VideoRTPSink.cpp
    liveMedia/H264or5VideoStreamDiscreteFramer.cpp
    liveMedia/H264or5VideoStreamFramer.cpp
    liveMedia/H264VideoFileServerMediaSubsession.cpp
    liveMedia/H264VideoFileSink.cpp
    liveMedia/H264VideoRTPSink.cpp
    liveMedia/H264VideoRTPSource.cpp
    liveMedia/H264VideoStreamDiscreteFramer.cpp
    liveMedia/H264VideoStreamFramer.cpp
    liveMedia/H265VideoFileServerMediaSubsession.cpp
    liveMedia/H265VideoFileSink.cpp
    liveMedia/H265VideoRTPSink.cpp
    liveMedia/H265VideoRTPSource.cpp
    liveMedia/H265VideoStreamDiscreteFramer.cpp
    liveMedia/H265VideoStreamFramer.cpp
    liveMedia/HLSSegmenter.cpp
    liveMedia/HMAC_SHA1.cpp
    liveMedia/InputFile.cpp
    liveMedia/JPEG2000VideoRTPSink.cpp
    liveMedia/JPEG2000VideoRTPSource.cpp
    liveMedia/JPEGVideoRTPSink.cpp
    liveMedia/JPEGVideoRTPSource.cpp
    liveMedia/JPEGVideoSource.cpp
    liveMedia/Locale.cpp
    liveMedia/MatroskaDemuxedTrack.cpp
    liveMedia/MatroskaFile.cpp
    liveMedia/MatroskaFileParser.cpp
    liveMedia/MatroskaFileServerDemux.cpp
    liveMedia/MatroskaFileServerMediaSubsession.cpp
    liveMedia/Media.cpp
    liveMedia/MediaSession.cpp
    liveMedia/MediaSink.cpp
    liveMedia/MediaSource.cpp
    liveMedia/MIKEY.cpp
    liveMedia/MP3ADU.cpp
    liveMedia/MP3ADUdescriptor.cpp
    liveMedia/MP3ADUinterleaving.cpp
    liveMedia/MP3ADURTPSink.cpp
    liveMedia/MP3ADURTPSource.cpp
    liveMedia/MP3ADUTranscoder.cpp
    liveMedia/MP3AudioFileServerMediaSubsession.cpp
    liveMedia/MP3AudioMatroskaFileServerMediaSubsession.cpp
    liveMedia/MP3FileSource.cpp
    liveMedia/MP3Internals.cpp
    liveMedia/MP3InternalsHuffman.cpp
    liveMedia/MP3InternalsHuffmanTable.cpp
    liveMedia/MP3StreamState.cpp
    liveMedia/MP3Transcoder.cpp
    liveMedia/MPEG1or2AudioRTPSink.cpp
    liveMedia/MPEG1or2AudioRTPSource.cpp
    liveMedia/MPEG1or2AudioStreamFramer.cpp
    liveMedia/MPEG1or2Demux.cpp
    liveMedia/MPEG1or2DemuxedElementaryStream.cpp
    liveMedia/MPEG1or2DemuxedServerMediaSubsession.cpp
    liveMedia/MPEG1or2FileServerDemux.cpp
    liveMedia/MPEG1or2VideoFileServerMediaSubsession.cpp
    liveMedia/MPEG1or2VideoRTPSink.cpp
    liveMedia/MPEG1or2VideoRTPSource.cpp
    liveMedia/MPEG1or2VideoStreamDiscreteFramer.cpp
    liveMedia/MPEG1or2VideoStreamFramer.cpp
    liveMedia/MPEG2IndexFromTransportStream.cpp
    liveMedia/MPEG2TransportFileServerMediaSubsession.cpp
    liveMedia/MPEG2TransportStreamAccumulator.cpp
    liveMedia/MPEG2TransportStreamDemux.cpp
    liveMedia/MPEG2TransportStreamDemuxedTrack.cpp
    liveMedia/MPEG2TransportStreamFramer.cpp
    liveMedia/MPEG2TransportStreamFromESSource.cpp
    liveMedia/MPEG2TransportStreamFromPESSource.cpp
    liveMedia/MPEG2TransportStreamIndexFile.cpp
    liveMedia/MPEG2TransportStreamMultiplexor.cpp
    liveMedia/MPEG2TransportStreamParser.cpp
    liveMedia/MPEG2TransportStreamParser_PAT.cpp
    liveMedia/MPEG2TransportStreamParser_PMT.cpp
    liveMedia/MPEG2TransportStreamParser_STREAM.cpp
    liveMedia/MPEG2TransportStreamTrickModeFilter.cpp
    liveMedia/MPEG2TransportUDPServerMediaSubsession.cpp
    liveMedia/MPEG4ESVideoRTPSink.cpp
    liveMedia/MPEG4ESVideoRTPSource.cpp
    liveMedia/MPEG4GenericRTPSink.cpp
    liveMedia/MPEG4GenericRTPSource.cpp
    liveMedia/MPEG4LATMAudioRTPSink.cpp
    liveMedia/MPEG4LATMAudioRTPSource.cpp
    liveMedia/MPEG4VideoFileServerMediaSubsession.cpp
    liveMedia/MPEG4VideoStreamDiscreteFramer.cpp
    liveMedia/MPEG4VideoStreamFramer.cpp
    liveMedia/MPEGVideoStreamFramer.cpp
    liveMedia/MPEGVideoStreamParser.cpp
    liveMedia/MultiFramedRTPSink.cpp
    liveMedia/MultiFramedRTPSource.cpp
    liveMedia/OggDemuxedTrack.cpp
    liveMedia/OggFile.cpp
    liveMedia/OggFileParser.cpp
    liveMedia/OggFileServerDemux.cpp
    liveMedia/OggFileServerMediaSubsession.cpp
    liveMedia/OggFileSink.cpp
    liveMedia/OnDemandServerMediaSubsession.cpp
    liveMedia/ourMD5.cpp
    liveMedia/OutputFile.cpp
    liveMedia/PassiveServerMediaSubsession.cpp
    liveMedia/ProxyServerMediaSession.cpp
    liveMedia/QCELPAudioRTPSource.cpp
    liveMedia/QuickTimeFileSink.cpp
    liveMedia/QuickTimeGenericRTPSource.cpp
    liveMedia/RawVideoRTPSink.cpp
    liveMedia/RawVideoRTPSource.cpp
    liveMedia/RTCP.cpp
    liveMedia/RTPInterface.cpp
    liveMedia/RTPSink.cpp
    liveMedia/RTPSource.cpp
    liveMedia/RTSPClient.cpp
    liveMedia/RTSPCommon.cpp
    liveMedia/RTSPRegisterSender.cpp
    liveMedia/RTSPServer.cpp
    liveMedia/RTSPServerRegister.cpp
    liveMedia/ServerMediaSession.cpp
    liveMedia/SimpleRTPSink.cpp
    liveMedia/SimpleRTPSource.cpp
    liveMedia/SIPClient.cpp
    liveMedia/SRTPCryptographicContext.cpp
    liveMedia/StreamParser.cpp
    liveMedia/StreamReplicator.cpp
    liveMedia/T140TextRTPSink.cpp
    liveMedia/TextRTPSink.cpp
    liveMedia/TheoraVideoRTPSink.cpp
    liveMedia/TheoraVideoRTPSource.cpp
    liveMedia/TLSState.cpp
    liveMedia/uLawAudioFilter.cpp
    liveMedia/VideoRTPSink.cpp
    liveMedia/VorbisAudioRTPSink.cpp
    liveMedia/VorbisAudioRTPSource.cpp
    liveMedia/VP8VideoRTPSink.cpp
    liveMedia/VP8VideoRTPSource.cpp
    liveMedia/VP9VideoRTPSink.cpp
    liveMedia/VP9VideoRTPSource.cpp
    liveMedia/WAVAudioFileServerMediaSubsession.cpp
    liveMedia/WAVAudioFileSource.cpp
    liveMedia/rtcp_from_spec.c
)

if (WIN32)
    target_link_libraries(livemedia PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        wsock32
        ws2_32
    )
else()
    target_link_libraries(livemedia PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
    )
endif()

target_include_directories(livemedia PUBLIC
    liveMedia/include
    groupsock/include
    UsageEnvironment/include
    BasicUsageEnvironment/include
)

set_target_properties(livemedia PROPERTIES
    SOVERSION 1
)

install(TARGETS livemedia DESTINATION "${CMAKE_INSTALL_LIBDIR}/")

install(FILES pkgconfig/liblivemedia.pc DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
install(FILES cmake/FindLiveMedia.cmake DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/LibLiveMedia/")

install(FILES
    groupsock/include/GroupEId.hh
    groupsock/include/Groupsock.hh
    groupsock/include/IOHandlers.hh
    groupsock/include/NetCommon.h
    groupsock/include/GroupsockHelper.hh
    groupsock/include/groupsock_version.hh
    groupsock/include/NetAddress.hh
    groupsock/include/NetInterface.hh
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/groupsock")

install(FILES
    BasicUsageEnvironment/include/BasicHashTable.hh
    BasicUsageEnvironment/include/BasicUsageEnvironment.hh
    BasicUsageEnvironment/include/DelayQueue.hh
    BasicUsageEnvironment/include/BasicUsageEnvironment0.hh
    BasicUsageEnvironment/include/BasicUsageEnvironment_version.hh
    BasicUsageEnvironment/include/HandlerSet.hh
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/BasicUsageEnvironment")

install(FILES
    UsageEnvironment/include/Boolean.hh
    UsageEnvironment/include/HashTable.hh
    UsageEnvironment/include/strDup.hh
    UsageEnvironment/include/UsageEnvironment.hh
    UsageEnvironment/include/UsageEnvironment_version.hh
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/UsageEnvironment")

install(FILES
    liveMedia/include/AC3AudioFileServerMediaSubsession.hh
    liveMedia/include/AC3AudioRTPSink.hh
    liveMedia/include/AC3AudioRTPSource.hh
    liveMedia/include/AC3AudioStreamFramer.hh
    liveMedia/include/ADTSAudioFileServerMediaSubsession.hh
    liveMedia/include/ADTSAudioFileSource.hh
    liveMedia/include/ADTSAudioStreamDiscreteFramer.hh
    liveMedia/include/AMRAudioFileServerMediaSubsession.hh
    liveMedia/include/AMRAudioFileSink.hh
    liveMedia/include/AMRAudioFileSource.hh
    liveMedia/include/AMRAudioRTPSink.hh
    liveMedia/include/AMRAudioRTPSource.hh
    liveMedia/include/AMRAudioSource.hh
    liveMedia/include/AudioInputDevice.hh
    liveMedia/include/AudioRTPSink.hh
    liveMedia/include/AVIFileSink.hh
    liveMedia/include/Base64.hh
    liveMedia/include/BasicUDPSink.hh
    liveMedia/include/BasicUDPSource.hh
    liveMedia/include/BitVector.hh
    liveMedia/include/ByteStreamFileSource.hh
    liveMedia/include/ByteStreamMemoryBufferSource.hh
    liveMedia/include/ByteStreamMultiFileSource.hh
    liveMedia/include/DeviceSource.hh
    liveMedia/include/DigestAuthentication.hh
    liveMedia/include/DVVideoFileServerMediaSubsession.hh
    liveMedia/include/DVVideoRTPSink.hh
    liveMedia/include/DVVideoRTPSource.hh
    liveMedia/include/DVVideoStreamFramer.hh
    liveMedia/include/FileServerMediaSubsession.hh
    liveMedia/include/FileSink.hh
    liveMedia/include/FramedFileSource.hh
    liveMedia/include/FramedFilter.hh
    liveMedia/include/FramedSource.hh
    liveMedia/include/GenericMediaServer.hh
    liveMedia/include/GSMAudioRTPSink.hh
    liveMedia/include/H261VideoRTPSource.hh
    liveMedia/include/H263plusVideoFileServerMediaSubsession.hh
    liveMedia/include/H263plusVideoRTPSink.hh
    liveMedia/include/H263plusVideoRTPSource.hh
    liveMedia/include/H263plusVideoStreamFramer.hh
    liveMedia/include/H264or5VideoFileSink.hh
    liveMedia/include/H264or5VideoRTPSink.hh
    liveMedia/include/H264or5VideoStreamDiscreteFramer.hh
    liveMedia/include/H264or5VideoStreamFramer.hh
    liveMedia/include/H264VideoFileServerMediaSubsession.hh
    liveMedia/include/H264VideoFileSink.hh
    liveMedia/include/H264VideoRTPSink.hh
    liveMedia/include/H264VideoRTPSource.hh
    liveMedia/include/H264VideoStreamDiscreteFramer.hh
    liveMedia/include/H264VideoStreamFramer.hh
    liveMedia/include/H265VideoFileServerMediaSubsession.hh
    liveMedia/include/H265VideoFileSink.hh
    liveMedia/include/H265VideoRTPSink.hh
    liveMedia/include/H265VideoRTPSource.hh
    liveMedia/include/H265VideoStreamDiscreteFramer.hh
    liveMedia/include/H265VideoStreamFramer.hh
    liveMedia/include/HLSSegmenter.hh
    liveMedia/include/HMAC_hash.hh
    liveMedia/include/HMAC_SHA1.hh
    liveMedia/include/InputFile.hh
    liveMedia/include/JPEG2000VideoRTPSink.hh
    liveMedia/include/JPEG2000VideoRTPSource.hh
    liveMedia/include/JPEGVideoRTPSink.hh
    liveMedia/include/JPEGVideoRTPSource.hh
    liveMedia/include/JPEGVideoSource.hh
    liveMedia/include/liveMedia.hh
    liveMedia/include/liveMedia_version.hh
    liveMedia/include/Locale.hh
    liveMedia/include/MatroskaFile.hh
    liveMedia/include/MatroskaFileServerDemux.hh
    liveMedia/include/Media.hh
    liveMedia/include/MediaSession.hh
    liveMedia/include/MediaSink.hh
    liveMedia/include/MediaSource.hh
    liveMedia/include/MediaTranscodingTable.hh
    liveMedia/include/MIKEY.hh
    liveMedia/include/MP3ADU.hh
    liveMedia/include/MP3ADUinterleaving.hh
    liveMedia/include/MP3ADURTPSink.hh
    liveMedia/include/MP3ADURTPSource.hh
    liveMedia/include/MP3ADUTranscoder.hh
    liveMedia/include/MP3AudioFileServerMediaSubsession.hh
    liveMedia/include/MP3FileSource.hh
    liveMedia/include/MP3Transcoder.hh
    liveMedia/include/MPEG1or2AudioRTPSink.hh
    liveMedia/include/MPEG1or2AudioRTPSource.hh
    liveMedia/include/MPEG1or2AudioStreamFramer.hh
    liveMedia/include/MPEG1or2DemuxedElementaryStream.hh
    liveMedia/include/MPEG1or2DemuxedServerMediaSubsession.hh
    liveMedia/include/MPEG1or2Demux.hh
    liveMedia/include/MPEG1or2FileServerDemux.hh
    liveMedia/include/MPEG1or2VideoFileServerMediaSubsession.hh
    liveMedia/include/MPEG1or2VideoRTPSink.hh
    liveMedia/include/MPEG1or2VideoRTPSource.hh
    liveMedia/include/MPEG1or2VideoStreamDiscreteFramer.hh
    liveMedia/include/MPEG1or2VideoStreamFramer.hh
    liveMedia/include/MPEG2IndexFromTransportStream.hh
    liveMedia/include/MPEG2TransportFileServerMediaSubsession.hh
    liveMedia/include/MPEG2TransportStreamAccumulator.hh
    liveMedia/include/MPEG2TransportStreamDemux.hh
    liveMedia/include/MPEG2TransportStreamFramer.hh
    liveMedia/include/MPEG2TransportStreamFromESSource.hh
    liveMedia/include/MPEG2TransportStreamFromPESSource.hh
    liveMedia/include/MPEG2TransportStreamIndexFile.hh
    liveMedia/include/MPEG2TransportStreamMultiplexor.hh
    liveMedia/include/MPEG2TransportStreamTrickModeFilter.hh
    liveMedia/include/MPEG2TransportUDPServerMediaSubsession.hh
    liveMedia/include/MPEG4ESVideoRTPSink.hh
    liveMedia/include/MPEG4ESVideoRTPSource.hh
    liveMedia/include/MPEG4GenericRTPSink.hh
    liveMedia/include/MPEG4GenericRTPSource.hh
    liveMedia/include/MPEG4LATMAudioRTPSink.hh
    liveMedia/include/MPEG4LATMAudioRTPSource.hh
    liveMedia/include/MPEG4VideoFileServerMediaSubsession.hh
    liveMedia/include/MPEG4VideoStreamDiscreteFramer.hh
    liveMedia/include/MPEG4VideoStreamFramer.hh
    liveMedia/include/MPEGVideoStreamFramer.hh
    liveMedia/include/MultiFramedRTPSink.hh
    liveMedia/include/MultiFramedRTPSource.hh
    liveMedia/include/OggFile.hh
    liveMedia/include/OggFileServerDemux.hh
    liveMedia/include/OggFileSink.hh
    liveMedia/include/OnDemandServerMediaSubsession.hh
    liveMedia/include/ourMD5.hh
    liveMedia/include/OutputFile.hh
    liveMedia/include/PassiveServerMediaSubsession.hh
    liveMedia/include/ProxyServerMediaSession.hh
    liveMedia/include/QCELPAudioRTPSource.hh
    liveMedia/include/QuickTimeFileSink.hh
    liveMedia/include/QuickTimeGenericRTPSource.hh
    liveMedia/include/RawVideoFrameParameters.hh
    liveMedia/include/RawVideoRTPSink.hh
    liveMedia/include/RawVideoRTPSource.hh
    liveMedia/include/RTCP.hh
    liveMedia/include/RTPInterface.hh
    liveMedia/include/RTPSink.hh
    liveMedia/include/RTPSource.hh
    liveMedia/include/RTSPClient.hh
    liveMedia/include/RTSPCommon.hh
    liveMedia/include/RTSPRegisterSender.hh
    liveMedia/include/RTSPServer.hh
    liveMedia/include/ServerMediaSession.hh
    liveMedia/include/SimpleRTPSink.hh
    liveMedia/include/SimpleRTPSource.hh
    liveMedia/include/SIPClient.hh
    liveMedia/include/SRTPCryptographicContext.hh
    liveMedia/include/StreamReplicator.hh
    liveMedia/include/T140TextRTPSink.hh
    liveMedia/include/TextRTPSink.hh
    liveMedia/include/TheoraVideoRTPSink.hh
    liveMedia/include/TheoraVideoRTPSource.hh
    liveMedia/include/TLSState.hh
    liveMedia/include/uLawAudioFilter.hh
    liveMedia/include/VideoRTPSink.hh
    liveMedia/include/VorbisAudioRTPSink.hh
    liveMedia/include/VorbisAudioRTPSource.hh
    liveMedia/include/VP8VideoRTPSink.hh
    liveMedia/include/VP8VideoRTPSource.hh
    liveMedia/include/VP9VideoRTPSink.hh
    liveMedia/include/VP9VideoRTPSource.hh
    liveMedia/include/WAVAudioFileServerMediaSubsession.hh
    liveMedia/include/WAVAudioFileSource.hh
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/liveMedia")
