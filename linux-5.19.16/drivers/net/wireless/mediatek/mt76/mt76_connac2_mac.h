/* SPDX-License-Identifier: ISC */
/* Copyright (C) 2022 MediaTek Inc. */

#ifndef __MT76_CONNAC2_MAC_H
#define __MT76_CONNAC2_MAC_H

enum tx_header_format {
	MT_HDR_FORMAT_802_3,
	MT_HDR_FORMAT_CMD,
	MT_HDR_FORMAT_802_11,
	MT_HDR_FORMAT_802_11_EXT,
};

enum tx_pkt_type {
	MT_TX_TYPE_CT,
	MT_TX_TYPE_SF,
	MT_TX_TYPE_CMD,
	MT_TX_TYPE_FW,
};

enum {
	MT_CTX0,
	MT_HIF0 = 0x0,

	MT_LMAC_AC00 = 0x0,
	MT_LMAC_AC01,
	MT_LMAC_AC02,
	MT_LMAC_AC03,
	MT_LMAC_ALTX0 = 0x10,
	MT_LMAC_BMC0,
	MT_LMAC_BCN0,
	MT_LMAC_PSMP0,
};

#define MT_TXD_SIZE			(8 * 4)
#define MT_SDIO_TXD_SIZE		(MT_TXD_SIZE + 8 * 4)
#define MT_SDIO_TAIL_SIZE		8
#define MT_SDIO_HDR_SIZE		4
#define MT_USB_TAIL_SIZE		4

#define MT_TXD0_Q_IDX			GENMASK(31, 25)
#define MT_TXD0_PKT_FMT			GENMASK(24, 23)
#define MT_TXD0_ETH_TYPE_OFFSET		GENMASK(22, 16)
#define MT_TXD0_TX_BYTES		GENMASK(15, 0)

#define MT_TXD1_LONG_FORMAT		BIT(31)
#define MT_TXD1_TGID			BIT(30)
#define MT_TXD1_OWN_MAC			GENMASK(29, 24)
#define MT_TXD1_AMSDU			BIT(23)
#define MT_TXD1_TID			GENMASK(22, 20)
#define MT_TXD1_HDR_PAD			GENMASK(19, 18)
#define MT_TXD1_HDR_FORMAT		GENMASK(17, 16)
#define MT_TXD1_HDR_INFO		GENMASK(15, 11)
#define MT_TXD1_ETH_802_3		BIT(15)
#define MT_TXD1_VTA			BIT(10)
#define MT_TXD1_WLAN_IDX		GENMASK(9, 0)

#define MT_TXD2_FIX_RATE		BIT(31)
#define MT_TXD2_FIXED_RATE		BIT(30)
#define MT_TXD2_POWER_OFFSET		GENMASK(29, 24)
#define MT_TXD2_MAX_TX_TIME		GENMASK(23, 16)
#define MT_TXD2_FRAG			GENMASK(15, 14)
#define MT_TXD2_HTC_VLD			BIT(13)
#define MT_TXD2_DURATION		BIT(12)
#define MT_TXD2_BIP			BIT(11)
#define MT_TXD2_MULTICAST		BIT(10)
#define MT_TXD2_RTS			BIT(9)
#define MT_TXD2_SOUNDING		BIT(8)
#define MT_TXD2_NDPA			BIT(7)
#define MT_TXD2_NDP			BIT(6)
#define MT_TXD2_FRAME_TYPE		GENMASK(5, 4)
#define MT_TXD2_SUB_TYPE		GENMASK(3, 0)

#define MT_TXD3_SN_VALID		BIT(31)
#define MT_TXD3_PN_VALID		BIT(30)
#define MT_TXD3_SW_POWER_MGMT		BIT(29)
#define MT_TXD3_BA_DISABLE		BIT(28)
#define MT_TXD3_SEQ			GENMASK(27, 16)
#define MT_TXD3_REM_TX_COUNT		GENMASK(15, 11)
#define MT_TXD3_TX_COUNT		GENMASK(10, 6)
#define MT_TXD3_TIMING_MEASURE		BIT(5)
#define MT_TXD3_DAS			BIT(4)
#define MT_TXD3_EEOSP			BIT(3)
#define MT_TXD3_EMRD			BIT(2)
#define MT_TXD3_PROTECT_FRAME		BIT(1)
#define MT_TXD3_NO_ACK			BIT(0)

#define MT_TXD4_PN_LOW			GENMASK(31, 0)

#define MT_TXD5_PN_HIGH			GENMASK(31, 16)
#define MT_TXD5_MD			BIT(15)
#define MT_TXD5_ADD_BA			BIT(14)
#define MT_TXD5_TX_STATUS_HOST		BIT(10)
#define MT_TXD5_TX_STATUS_MCU		BIT(9)
#define MT_TXD5_TX_STATUS_FMT		BIT(8)
#define MT_TXD5_PID			GENMASK(7, 0)

#define MT_TXD6_TX_IBF			BIT(31)
#define MT_TXD6_TX_EBF			BIT(30)
#define MT_TXD6_TX_RATE			GENMASK(29, 16)
#define MT_TXD6_SGI			GENMASK(15, 14)
#define MT_TXD6_HELTF			GENMASK(13, 12)
#define MT_TXD6_LDPC			BIT(11)
#define MT_TXD6_SPE_ID_IDX		BIT(10)
#define MT_TXD6_ANT_ID			GENMASK(7, 4)
#define MT_TXD6_DYN_BW			BIT(3)
#define MT_TXD6_FIXED_BW		BIT(2)
#define MT_TXD6_BW			GENMASK(1, 0)

#define MT_TXD7_TXD_LEN			GENMASK(31, 30)
#define MT_TXD7_UDP_TCP_SUM		BIT(29)
#define MT_TXD7_IP_SUM			BIT(28)
#define MT_TXD7_TYPE			GENMASK(21, 20)
#define MT_TXD7_SUB_TYPE		GENMASK(19, 16)

#define MT_TXD7_PSE_FID			GENMASK(27, 16)
#define MT_TXD7_SPE_IDX			GENMASK(15, 11)
#define MT_TXD7_HW_AMSDU		BIT(10)
#define MT_TXD7_TX_TIME			GENMASK(9, 0)

#define MT_TXD8_L_TYPE			GENMASK(5, 4)
#define MT_TXD8_L_SUB_TYPE		GENMASK(3, 0)

#define MT_TX_RATE_STBC			BIT(13)
#define MT_TX_RATE_NSS			GENMASK(12, 10)
#define MT_TX_RATE_MODE			GENMASK(9, 6)
#define MT_TX_RATE_SU_EXT_TONE		BIT(5)
#define MT_TX_RATE_DCM			BIT(4)
/* VHT/HE only use bits 0-3 */
#define MT_TX_RATE_IDX			GENMASK(5, 0)

#define MT_TXS0_FIXED_RATE		BIT(31)
#define MT_TXS0_BW			GENMASK(30, 29)
#define MT_TXS0_TID			GENMASK(28, 26)
#define MT_TXS0_AMPDU			BIT(25)
#define MT_TXS0_TXS_FORMAT		GENMASK(24, 23)
#define MT_TXS0_BA_ERROR		BIT(22)
#define MT_TXS0_PS_FLAG			BIT(21)
#define MT_TXS0_TXOP_TIMEOUT		BIT(20)
#define MT_TXS0_BIP_ERROR		BIT(19)

#define MT_TXS0_QUEUE_TIMEOUT		BIT(18)
#define MT_TXS0_RTS_TIMEOUT		BIT(17)
#define MT_TXS0_ACK_TIMEOUT		BIT(16)
#define MT_TXS0_ACK_ERROR_MASK		GENMASK(18, 16)

#define MT_TXS0_TX_STATUS_HOST		BIT(15)
#define MT_TXS0_TX_STATUS_MCU		BIT(14)
#define MT_TXS0_TX_RATE			GENMASK(13, 0)

#define MT_TXS1_SEQNO			GENMASK(31, 20)
#define MT_TXS1_RESP_RATE		GENMASK(19, 16)
#define MT_TXS1_RXV_SEQNO		GENMASK(15, 8)
#define MT_TXS1_TX_POWER_DBM		GENMASK(7, 0)

#define MT_TXS2_BF_STATUS		GENMASK(31, 30)
#define MT_TXS2_LAST_TX_RATE		GENMASK(29, 27)
#define MT_TXS2_SHARED_ANTENNA		BIT(26)
#define MT_TXS2_WCID			GENMASK(25, 16)
#define MT_TXS2_TX_DELAY		GENMASK(15, 0)

#define MT_TXS3_PID			GENMASK(31, 24)
#define MT_TXS3_ANT_ID			GENMASK(23, 0)

#define MT_TXS4_TIMESTAMP		GENMASK(31, 0)

#endif /* __MT76_CONNAC2_MAC_H */
