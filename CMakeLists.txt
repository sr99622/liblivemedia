#/*********************************************************
#
# Copyright (c) 2022, 2024 Stephen Rhodes
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at your
# option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
# more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
#
#***********************************************************/

cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
project(liblivemedia VERSION 1.0.0)
#find_package(OpenSSL REQUIRED)
set(CMAKE_CXX_FLAGS "-DSOCKLEN_T=socklen_t -DNO_OPENSSL=1")
include(GNUInstallDirs)
set(CMAKE_INSTALL_INCLUDEDIR "include/${CMAKE_LIBRARY_ARCHITECTURE}")

if(WIN32)
    add_compile_options("/EHsc")
    add_compile_definitions("NO_GETIFADDRS")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

add_subdirectory(pybind11)

pybind11_add_module(liblivemedia
    
    MyApps/liblivemedia.cpp

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

#target_link_libraries(liblivemedia PRIVATE
#    OpenSSL::SSL
#    OpenSSL::Crypto
#)

if (WIN32)
    target_link_libraries(liblivemedia PRIVATE
        wsock32
        ws2_32    
    )
endif()

target_include_directories(liblivemedia SYSTEM PUBLIC
    liveMedia/include
    groupsock/include
    UsageEnvironment/include
    BasicUsageEnvironment/include
    MyApps/ProxyServer/include
)

