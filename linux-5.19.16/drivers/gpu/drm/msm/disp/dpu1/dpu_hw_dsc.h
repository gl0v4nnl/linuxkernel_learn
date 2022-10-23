/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2020-2022, Linaro Limited */

#ifndef _DPU_HW_DSC_H
#define _DPU_HW_DSC_H

#include <drm/display/drm_dsc.h>

#define DSC_MODE_SPLIT_PANEL            BIT(0)
#define DSC_MODE_MULTIPLEX              BIT(1)
#define DSC_MODE_VIDEO                  BIT(2)

struct dpu_hw_dsc;

/**
 * struct dpu_hw_dsc_ops - interface to the dsc hardware driver functions
 * Assumption is these functions will be called after clocks are enabled
 */
struct dpu_hw_dsc_ops {
	/**
	 * dsc_disable - disable dsc
	 * @hw_dsc: Pointer to dsc context
	 */
	void (*dsc_disable)(struct dpu_hw_dsc *hw_dsc);

	/**
	 * dsc_config - configures dsc encoder
	 * @hw_dsc: Pointer to dsc context
	 * @dsc: panel dsc parameters
	 * @mode: dsc topology mode to be set
	 * @initial_lines: amount of initial lines to be used
	 */
	void (*dsc_config)(struct dpu_hw_dsc *hw_dsc,
			   struct msm_display_dsc_config *dsc,
			   u32 mode,
			   u32 initial_lines);

	/**
	 * dsc_config_thresh - programs panel thresholds
	 * @hw_dsc: Pointer to dsc context
	 * @dsc: panel dsc parameters
	 */
	void (*dsc_config_thresh)(struct dpu_hw_dsc *hw_dsc,
				  struct msm_display_dsc_config *dsc);
};

struct dpu_hw_dsc {
	struct dpu_hw_blk base;
	struct dpu_hw_blk_reg_map hw;

	/* dsc */
	enum dpu_dsc idx;
	const struct dpu_dsc_cfg *caps;

	/* ops */
	struct dpu_hw_dsc_ops ops;
};

/**
 * dpu_hw_dsc_init - initializes the dsc block for the passed dsc idx.
 * @idx:  DSC index for which driver object is required
 * @addr: Mapped register io address of MDP
 * @m:    Pointer to mdss catalog data
 * Returns: Error code or allocated dpu_hw_dsc context
 */
struct dpu_hw_dsc *dpu_hw_dsc_init(enum dpu_dsc idx, void __iomem *addr,
				   struct dpu_mdss_cfg *m);

/**
 * dpu_hw_dsc_destroy - destroys dsc driver context
 * @dsc:   Pointer to dsc driver context returned by dpu_hw_dsc_init
 */
void dpu_hw_dsc_destroy(struct dpu_hw_dsc *dsc);

static inline struct dpu_hw_dsc *to_dpu_hw_dsc(struct dpu_hw_blk *hw)
{
	return container_of(hw, struct dpu_hw_dsc, base);
}

#endif /* _DPU_HW_DSC_H */
